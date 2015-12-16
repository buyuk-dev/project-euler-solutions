/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Compute N-th prime number. 
    TODO: use faster primality test algorithm.
    TODO: increase step in main loop.
    TRY: sieve algorithm possibly might work better if we
         estimate the upper limit.
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


bool isPrime(int n) {
    // test up to sqrt(n)
    for (int i=2; i*i<=n; ++i) {
        if (n%i == 0) {
            return false;
        } 
    }
    return true;
}



int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int counter = 0;
    int number = 1;
    int index;
    cin >> index;
    while (counter < index) {
        number += 1;
        if(isPrime(number)) {
            cout << "prime found: " << number << endl;
            counter++;
        }
    }
    cout << "number is " << number << endl;

    return 0;
}







