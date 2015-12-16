/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Compute the largest prime factor for a 
    given integer n.    
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



void sieve(vector<bool>& primes) {
    primes[0] = primes[1] = false;

    for (int step=2; step<primes.size(); step++) {
        for (int i=2*step; i<primes.size(); i+=step) {
            primes[i] = false;
        } 
    } 
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);
    
    long number = 0;
    cin >> number;
    
    vector<bool> primes(int(sqrt(number)), true);
    sieve(primes);
    
    for (int i=primes.size()-1; i>=0; --i) {
        if (primes[i] && (number % i == 0)) {
            cout << "result: " << i << endl;
            break;
        }        
    }    
    
    return 0;
}







