#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# sum of all multiples of 3 or 5 below 1000
#

def load(filename):

    data = None

    with open(filename, "r") as dataFile:
        line = dataFile.readline()
        data = line.split()
        data = [int(n) for n in data]

    return data


def sumOfMultiplesOfN(n, limit):

    kmax = limit // n
    return n * (kmax * (kmax + 1) / 2)


def solve(a, b, lim):

    sumA = sumOfMultiplesOfN(a, lim)
    sumB = sumOfMultiplesOfN(b, lim)
    sumAB = sumOfMultiplesOfN(a * b, lim)
    
    return sumA + sumB - sumAB


if __name__ == '__main__':

    a, b, lim = load("data/problem001.dat")
    
    result = solve(a, b, lim - 1)

    print "Sum of multiples of ", a, " or ", b, " under ", lim, " is ", result
