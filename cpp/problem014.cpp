/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Compute starting number uunder N which produces
    the longest Collatz sequence.
*/


#include <iostream>

using namespace std;

long collatz(long n) {

    long counter = 1;
    while (n>1) {
        if (n&1) {
            n = 3*n+1;
        } else {
            n = n >> 1;
        }
        counter ++;
    }
    return counter;
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    long N;
    cin >> N;

    long max = 0;
    long num = -1;
    for(long i=1; i<=N; ++i) {
        long csl = collatz(i);
        if (max < csl) {
            max = csl;
            num = i;
        } 
    }

    cout << "collatz sequence for " 
         << num << " has length " 
         << max << endl;
    
    return 0;
}







