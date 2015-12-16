/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    Compute Pythagorean triplet for which a+b+c == 1000
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

    for (int a=1; a<1000; ++a) {
        for (int b=a; b<1000; ++b) {
            int c = sqrt(a*a + b*b);
            if (a+b+c == 1000 && a*a + b*b == c*c) {
                cout << a << " " << b << " " << c << endl;
                break;
            }
        }
    }
    
    return 0;
}







