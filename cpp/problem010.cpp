/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Find the sum of all primes below N.
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


void sieve(vector<bool>& P) {
    P[0] = P[1] = false;
    int step = 2;
    while (step < P.size()) {
        for (int i=2*step; i<P.size(); i+=step)
            P[i] = false;
        do {
            step ++; 
        } while (step < P.size() && !P[step]);
    }
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<bool> P(N, true);
    sieve(P);

    long sum = 0;
    for (long i=0; i<P.size(); ++i) {
        if (P[i]) {
            //cout << i << " is a prime.\n";
            sum += i;
        }
    }
    cout << "Sum of all primes below " << N << " is " << sum << endl;

    return 0;
}







