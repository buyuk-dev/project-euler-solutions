#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Non-abundant sums.
#
from math import sqrt

filename = "data/problem023.dat";
inputFile = open(filename, "r")


def load(filename):
    return None


def sumProperDivisors(n):
    s = 1
    pierw = int(sqrt(n))
    for i in range(2, pierw):
        if n % i == 0:
            s += i
            s += n // i
    return s


def isAbundant(n):
    s = sumProperDivisors(n)
    if s > n:
        return True
    else:
        return False


def generateAbundants(lim):
    return [n for n in range(12, lim) if isAbundant(n)]


def isSumOfTwoExt(n, numbers, bits):
    for i in numbers:
        if i > n: 
            break

        if bits[n - i]:
            return True
    return False


def isSumOfTwo(n, numbers, bits = None):
    ''' assuming numbers is a sorted list '''

    if bits is not None:
        return isSumOfTwoExt(n, numbers, bits)

    for i in numbers:
        if (n - i) in numbers:
            return True
    return False



def convertToBits(L):
    bits = [False] * (L[-1] + 1)
    for e in L:
        bits[e] = True
    return bits


if __name__ == '__main__':

    lim = 28123
    abundants = generateAbundants(lim)
    bits = convertToBits(abundants)

    s = 0
    for i in range(1, lim):
        if not isSumOfTwo(i, abundants, bits):
            s += i

    print "non abundant sum is ", s
