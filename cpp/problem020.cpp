/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    Calculate sum of digits in number 100!
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int base = 1000000;
 
vector<int> mul10e6(vector<int>& num, short int n)
{
    vector<int> result;
    int carry = 0, dnew = 0, digit = 0;

    for (int dnum = 0; dnum < num.size(); ++dnum)
    {
        digit = num[dnum];
        dnew = (digit * n + carry) % base;
        carry = (digit * n + carry) / base;
        result.push_back(dnew);
    }
 
    if (carry)
    {
        result.push_back(carry);
    }

    return result;
}
 
 
string convert2dec(vector<int>& A)
{
    ostringstream oss;
    for (int d: A)
    {
        oss << d;
    }
    return oss.str();
}
 
 
int charToInt(char digit)
{
   return digit - '0';
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
    vector<int> num;
    num.push_back(1);
 
    for (int i=1; i <= 100; ++i)
    {
        num = mul10e6(num, i);
    }

    reverse(num.begin(), num.end());
    string res = convert2dec(num);

    cout << digisum(res) << endl;
 
    return 0;
}
