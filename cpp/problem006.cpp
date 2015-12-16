/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Find the difference between the sum of squares of the
    first N natural numbers and the square of the sum.
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






int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    
    int diff = 0;
    int sum_of_squares = 0;
    for(int i=1; i<=n; ++i) {
        sum_of_squares += i*i;
    }

    int square_of_sum = 0;
    int sum = n*(n+1) / 2;
    square_of_sum = sum * sum;
    
    cout << "sum of squares " << sum_of_squares << endl;
    cout << "square of sum " << square_of_sum << endl;

    diff = square_of_sum - sum_of_squares;
    cout << diff << endl;

    return 0;
}







