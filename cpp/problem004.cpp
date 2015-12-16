/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Find the largest palindrome made from the
    product of two n-digit numbers.
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)



using namespace std;



int toString(int n, char* buf) {
    int counter = 0;
    while( n>0 ) {
        buf[counter++] = n%10 + '0';
        n /= 10;
    }
    buf[counter] = '\0';
    return counter;
}



bool isPalindrome(int n) {
    char digits[10];
    int len = toString(n, digits);
    int beg = 0, end = len-1;
    while( beg < end ) {
        if(digits[beg++] != digits[end--]) {
            return false;
        }
    }
    return true;
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int max = 0;
    for(int i=100; i<1000; ++i) {
        for(int j=i; j<1000; ++j) {
            if (isPalindrome(i*j)) {
                cout << i << " * " << j << " = " << i*j << " is a palindrome." << endl;
                if (i*j > max) max = i*j;
            }
        }
    } 
    cout << "max palindrome is " << max << endl;
    return 0;
}







