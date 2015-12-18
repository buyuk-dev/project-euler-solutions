/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Compute number of routes in NxN grid where you
    can move either Right or Down from the top left 
    corner to the bottom right corner.
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
#include <cstdint>


#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)



using namespace std;


// important trick in the equation is to first multiply 
// res by n+i and then divide by i, which prevents fractions.
uint64_t calc(uint64_t n) {
    uint64_t  res = 1;
    for(uint64_t i=1; i<=n; ++i) {
        res = (res * (n+i)) / i;
    }
    return res;
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
            
    cout << "computed number of different routes: " << calc(N) << endl;

    return 0;
}







