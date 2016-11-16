/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    Compute sum of all amicable numbers 
    under 10000.
*/

#include <cstdio>
#include <vector>


using namespace std;


const int lim = 10000;
vector<int> D(lim * 100, -1);

int d(int n)
{
    if (D[n] == -1)
    {
        D[n] = 0;
        for (int div = 1; div < n; ++div)
        {
            if (n % div == 0)
            {
                D[n] += div;
            }
        }
    }

    return D[n];
}


bool isAmicable(int n)
{
    return n != d(n) && d(d(n)) == n;
}


int main(int argc, char* argv[]) 
{
    int sum = 0;
    for (int i = 1; i < lim; ++i)
    {
        if (isAmicable(i))
        {
            sum += i;
        }
    }    

    printf("Sum of all amicable numbers lower than %d equals %d\n", lim, sum);
    return 0;
}







