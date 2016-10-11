/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Find the smallest number evenly divisible
    by all numbers from 1 to N.
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


const int N=20;
const int primes[N+1] = {2,3,5,7,11,13,17,19,0};


#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)



using namespace std;



int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int x = 1;
    for (int i=0; i<N; ++i)
    {
        // watch for last prime in array.
        if (primes[i] == 0) break;
        
        // figure out the largest exponent of i-th prime lower than or equal N
        int p = primes[i];
        int pp = p;
        while (pp * p <= N) pp *= p;
        
        // include the exponent in result
        x *= pp;
    }
    printf("Smallest number evenly divisible by all numbers in range 1..%d is %d\n", N, x);
    return 0;
}







