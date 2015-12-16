/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Find the greatest product of N adjacent numbers
    in the same direction in the 2D array.
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>

#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)



using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

typedef struct  Pair {
    int x, y;
    Pair(int x, int y)
        : x(x), y(y) {}
} Direction;


bool inRange(Pair p, Matrix& m) {
    return p.x >= 0 && p.y >= 0 && 
           p.x < m.size() && p.y < m[0].size();
}


int product(Matrix& m, Pair pos, Direction dir, int len) {
    int prod = 1;
    int counter = 1;
    do {
        prod *= m[pos.x][pos.y];
        pos.x += dir.x;
        pos.y += dir.y;
    } 
    while (counter++ < len);
    return prod;
}


void readMatrix(Matrix& M, string filename) {
    ifstream ifs(filename.c_str());
    if (!ifs) {
        throw string("input file error");
    }

    string line;
    int row = 0;
    while (getline(ifs, line)) {
        M.push_back(Vector());
        istringstream parser(line);
        int elem = 0;
        while (parser >> elem) {
            M[row].push_back(elem);
        }
        row ++;
    }
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);
   
    vector<Direction> dirs(8, Pair(0,0));
    dirs[0] = Direction(-1, -1);
    dirs[1] = Direction(-1,  0);
    dirs[2] = Direction(-1,  1);
    dirs[3] = Direction( 0, -1);
    dirs[4] = Direction( 0,  1);
    dirs[5] = Direction( 1, -1);
    dirs[6] = Direction( 1,  0);
    dirs[7] = Direction( 1,  1);

    string inputFile;
    int N; 
    Matrix M;

    cin >> N;
    cin >> inputFile;
    readMatrix(M, inputFile);  
    
    int sizex = M.size(), sizey = M[0].size();
    int maxprod = 0;
    for (int x=0; x<sizex; ++x) {
        for (int y=0; y<sizey; ++y) {
            for (auto d=dirs.begin(); d != dirs.end(); ++d) {
                Pair lim(x+(d->x*N), y+(d->y*N));
                if (inRange(lim, M)) {
                    int prod = product(M, Pair(x,y), *d, N);
                    if (prod > maxprod) 
                        maxprod = prod;
                }           
            }
        }
    }

    cout << "max product of length " << N 
         << " in the given matrix is " << maxprod 
         << endl;

    return 0;
}







