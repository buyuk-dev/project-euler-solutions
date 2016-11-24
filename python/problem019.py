#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Counting Sundays
#

months = [ 
    'jan', 'feb', 'mar', 'apr', 'may', 'jun',
    'jul', 'aug', 'sep', 'oct', 'nov', 'dec' 
]

monthsLengths = { 
    'jan': 31, 'feb': 28, 'mar': 31, 'apr': 30, 
    'may': 31, 'jun': 30, 'jul': 31, 'aug': 31,
    'sep': 30, 'oct': 31, 'nov': 30, 'dec': 31 
}

daysOfWeek = { 
    'mon': 0, 'tue': 1, 'wed': 2, 'thu': 3, 
    'fri': 4, 'sat': 5, 'sun': 6 
}



def isLeapYear(year):

    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)


def getMonthLength(year, month):

    month = months[month]
    days = monthsLengths[month]

    if month == 'feb' and isLeapYear(year):
        days += 1

    return days


def countDays(begYear, endYear, day):

    first = sundays = 0
    
    for year in range(begYear, endYear):
        for month in range( len(months) ):

            first += getMonthLength(year, month)
            first = first % len(daysOfWeek)
            
            if year > 1900 and first == daysOfWeek[day]:
                
                sundays += 1

    return sundays


if __name__ == '__main__':

    sundays = countDays(1900, 2001, 'sun')

    print "1st day of a month was Sunday exactly ", sundays, " times."
