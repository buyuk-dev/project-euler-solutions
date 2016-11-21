#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Summation of primes
# 

from math import sqrt


def removeMultiples(X, k):

    return [x for x in X if (x % k != 0 or x == k)]

    
    
def sieve(n):
    
    primes = [2] + [i for i in range(3, n, 2)]

    filter = 0
    while primes[filter] <= sqrt(n):
        primes = removeMultiples(primes, primes[filter])
        filter += 1
        
    return primes


if __name__ == "__main__":

    n = 2000000
    
    primes = sieve(n)
    result = sum(primes)
    
    print "sum of primes below ", n, " is equal to ", result

