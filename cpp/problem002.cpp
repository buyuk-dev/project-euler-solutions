/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    find the sum of even fibbonacci numbers
    below 1 000 000.
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


int evenFibSum(int n) {
    int a = 0, b = 2;
    int sum = 0;
    while (b <= n) {
        int tmp = a;
        a = b;
        b = 4*b + tmp;
        sum += a;
    }
    return sum;
}


int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    cout << "sum = " << evenFibSum(n) << endl;
    
    return 0;
}







