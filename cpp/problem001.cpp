/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    Calculate sum of all multiples of 3 or 5
    below 1000.
*/

#include <cstdio>


int sumOfMultiplesOfN(int n, int limit)
{
   int kmax = limit / n;
   return n * (kmax * (kmax + 1) / 2);
}

int main()
{
   int sum3 = sumOfMultiplesOfN(3, 999);
   int sum5 = sumOfMultiplesOfN(5, 999);
   int sum15 = sumOfMultiplesOfN(15, 999);
   
   int sum3or5 = sum3 + sum5 - sum15;
   
   printf("Sum of multiples of 3 or 5 below 1000 is %d\n", sum3or5);
   return 0;
}
