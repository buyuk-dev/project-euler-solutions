/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    << INSERT DESCRIPTION HERE >>
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



vector<int> sumAll(vector<string>& nums, int len) {
    vector<int> sum;
    for(int i=0; i<len; ++i) {
        int partial = 0;
        for(int j=0; j<nums.size(); ++j) {
            partial += nums[j][i] - '0';
        }
        sum.push_back(partial);
    }
    return sum;
}


void carry(vector<int>& v) {
    int i=0, d, c;
    do {
        c = v[i] / 10;
        d = v[i] - (10*c);
        v[i] = d;
        if(i+1 < v.size())
            v[i+1] += c;
        else 
            v.push_back(c);
        ++i;
    } while (c > 0);
}



int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);
    
    if (argc < 2) {
        cerr << "Input filename must be provided as a command line argument.\n";
        return -1;
    }

    cout << "Input file is " << argv[1] << endl;
    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "Problem oppening input file.\n";
        return -2;
    } 

    vector<string> nums;

    string num;
    while (ifs >> num) {
        reverse(num.begin(), num.end());
        nums.push_back(num);
    }

    auto S = sumAll(nums, nums[0].size());
    carry(S);
    reverse(S.begin(), S.end());

    for (int i=0; i<S.size(); ++i) {
        cout << S[i] << " ";
    }
    cout << endl;
 
    return 0;
}







