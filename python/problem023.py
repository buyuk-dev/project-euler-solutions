#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Non-abundant sums.
#

filename = "data/problem023.dat";
inputFile = open(filename, "r")


def load(filename):
    return None


def sumProperDivisors(n):
    s = 1
    for i in range(2, n):
        if n % i == 0:
            s += i
    return s


def isAbundant(n):
    s = sumProperDivisors(n)
    if s > n:
        return True
    else:
        return False


def generateAbundants(lim):
    return [n for n in range(12, lim) if isAbundant(n)]


def isSumOfTwo(n, numbers):
    ''' assuming numbers is a sorted list '''
    for i in numbers:
        if (n - i) in numbers:
            return True
    return False


if __name__ == '__main__':

    lim = 28123
    abundants = generateAbundants(lim)

    s = 0
    for i in range(1, lim):
        if i % 100 == 0:
            print i, " ..."
        if isSumOfTwo(i, abundants):
            s += i

    print "non abundant sum is ", s
