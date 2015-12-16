/*
    Copyright (c) 2015 - Michał Michalski
    -------------------------------------
    Compute the value of the first triangle number 
    to have over N divisors.
    TODO: improve divisors(n) complexity
    TODO: compute divisors(n) on demand instead of precomputing it.
*/


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>


#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)



using namespace std;


vector<int> D;


// computes number of divisors for any integer n
int divisors(int n) {
    int divs = 0;
    for (int i=1; i<=n; ++i) {
        if (n % i == 0) {
            divs ++;
        }
    }
    return divs;
}


// compute number of divisors for Tn
int triDivisors(int n) {
    if (n%2 == 0) {
        return D[n/2] * D[n+1];
    }
    return D[(n+1)/2] * D[n];
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    // precompute d(N) for small N
    D.push_back(-1);
    for (int i=1; i<50000; ++i) {
        int divs = divisors(i);
        D.push_back(divs);
    }

    int divLim;
    cin >> divLim;

    int d = 0, n=0;
    do {
        ++ n;
        d = triDivisors(n);
        cout << "T[" << n << "] has " << d << " divisors.\n";
    } while (d<divLim && n+1<D.size());
    cout << (n*(n+1))/2;

    return 0;
}







