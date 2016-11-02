/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    Calculate sum of digits in 2^1000.
*/
#include <cstdio>
#include <algorithm>
#include <string>


using namespace std;


int charToInt(char digit)
{
   return digit - '0';
}


char intToChar(int digit)
{
   return '0' + digit;
}


string mul2(const string& num)
{
   string result = "";
   int carry = 0, dnew = 0, digit = 0;
   
   for (int dnum = 0; dnum < num.size(); ++dnum)
   {
      digit = charToInt(num[dnum]);
      dnew = (digit * 2 + carry) % 10;
      carry = (digit * 2 + carry) / 10;
      result += intToChar(dnew);
   }
   
   if (carry)
   {
      result += intToChar(carry);
   }
   
   return result;
}


int digisum(const string& num)
{
   int sum = 0;
   for (int i=0; i<num.size(); ++i)
   {
      sum += charToInt(num[i]);
   }
   return sum;
}


int main()
{
   string num = "1";
   for (int i = 1; i <= 1000; ++i)
   {
      num = mul2(num);
   }
   
   printf("Sum of digits in 2^1000 is %d\n", digisum(num));
   return 0;
}
