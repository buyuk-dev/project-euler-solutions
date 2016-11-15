#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# sum all of amicable numbers below 10000
#

MAX = 10000


D = [None] * MAX * 100


def d(n):
    """ calculate sum of proper divisors of n """
    
    if D[n] is None:
        
        D[n] = 0
        for divisor in range(1, n):
            if n % divisor == 0:
                D[n] += divisor

    return D[n]



def main():
    """ calculate sum of amicable numbers below MAX """    
    
    summary = 0
    for i in range(1, 10000):

        if i == d(d(i)) and i != d(i):
            summary += i

    print summary


if __name__ == '__main__':
    main()
