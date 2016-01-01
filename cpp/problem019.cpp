/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    How many sundays happend on first day of a month
    between 1 Jan 1901 and 31 Dec 2000?
*/


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>



#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)



using namespace std;


const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline bool isLeapYear(const int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int monthLength(int year, int month) {
    int days = 0;
    if (month != 1) {
        days = months[month];
    }
    else if (isLeapYear(year)) {
        days = 29;
    }
    return days;
}

int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0);

    int firstDay = 0, sundaysCounter = 0;
    for (int year=1900; year<2001; ++year) {
        for (int month=0; month<12; ++month) {
            firstDay += monthLength(year, month);
            firstDay %= 7;
            if (year > 1900 && firstDay == 6) {
                sundaysCounter ++;
            }
        }
    }
    
    cout << "counted months starting at sunday between 1901 and 2001: " << sundaysCounter << endl;
    return 0;
}







