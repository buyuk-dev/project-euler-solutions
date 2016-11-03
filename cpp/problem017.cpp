/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    Problem 17 - Number letter counts
*/


#include <iostream>
#include <vector>
#include <cctype>
#include <string>


using namespace std;


const int numsnum = 1001;
vector<string> numbers(numsnum);


int count(const string& s)
{
   int counter = 0;
   for (int i = 0; i < s.size(); ++i)
   {
      if (isalpha(s[i]))
      {
         ++counter;
      }
   }
   return counter;
}


int main(int argc, char* argv[]) 
{
   string units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
   for (int i = 0; i < 10; ++i)
   {
      numbers[i] = units[i];
   }

   string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
   for (int i = 1; i < 10; ++i)
   {
      numbers[i * 10] = tens[i - 1];
   }
   
   for (int ten = 10; ten < 100; ten += 10)
   {
      for (int unit = 1; unit < 10; ++unit)
      {
         numbers[ten + unit] = numbers[ten] + "-" + numbers[unit];
      }
   }
   
   string dozen[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
   for (int i = 1; i < 10; ++i)
   {
      numbers[10 + i] = dozen[i - 1];
   }
   
   for (int hun = 100; hun < 1000; hun += 100)
   {
      for (int ten = 0; ten < 100; ++ten)
      {
         numbers[hun + ten] = numbers[ten/100] + " " + "hundred";
         if (ten > 0)
         {
            numbers[hun + ten] += " and " + numbers[ten];
         }
      }
   }
   
   numbers[1000] = "one thousand";
   
   int lettersCounter = 0;
   for (int num = 1; num < numsnum; ++num)
   {
      lettersCounter += count(numbers[num]);
   }
   
   cout << "Letters count in numbers up to 1000 excluding zero is " << lettersCounter;
   return 0;
}
