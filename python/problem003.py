#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# compute largest prime factor for n
#

from math import sqrt


def sieve(lim):

    primes = [True] * (lim + 1)
    primes[0] = primes[1] = False

    for k in range(2, len(primes)):
        for i in range(k * 2, len(primes), k):
            primes[i] = False

    return [n for n, p in enumerate(primes) if p]


if __name__ == '__main__':

    num = 600851475143
    size = int(sqrt(num));

    primes = sieve(size)

    for p in reversed(primes):
        if num % p == 0:
            print "largest prime factor in ", num, " is ", p
            break

