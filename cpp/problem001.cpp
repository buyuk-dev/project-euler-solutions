/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    Calculate sum of all multiples of 3 or 5
    below 1000.
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


struct Data
{
    int a, b, lim;
};


Data load()
{
    Data data;

    cin >> data.a >> data.b >> data.lim;

    return data;
}


int sumOfMultiplesOfN(int n, int limit)
{
   int kmax = limit / n;
   return n * (kmax * (kmax + 1) / 2);
}


int solve(int a, int b, int lim)
{
    int sumA = sumOfMultiplesOfN(a, lim - 1);
    int sumB = sumOfMultiplesOfN(b, lim - 1);
    int sumAB = sumOfMultiplesOfN(a * b, lim - 1);

    return sumA + sumB - sumAB;
}


int main()
{
    try 
    {
        Data data = load();

        int result = solve(data.a, data.b, data.lim);

        printf("Sum of multiples of %d or %d below %d is %d\n",
               data.a, data.b, data.lim, result);
    }
    catch (string err)
    {
        fprintf(stderr, "[ ERROR ] %s.\n", err.c_str());
    }
    return 0;
}
