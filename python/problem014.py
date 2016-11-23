#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Longest collatz sequence
#

def load(filename):

    data = 0
    with open(filename, "r") as dataFile:
        line = dataFile.readline()
        data = int(line)

    return data


def computeLength(n):

    counter = 1
    while n > 1:
        if n % 2 == 1:
            n = 3 * n + 1
        else:
            n = n // 2
        counter += 1

    return counter


def collatz(COL, n):

    if COL[n] is None:
        COL[n] = computeLength(n)

    return COL[n]


if __name__ == '__main__':

    n = load("data/problem014.dat")
    
    COL = [None] * (n + 1) 
    
    longest, best = (-1, -1)
    for i in range(n, 0, -1):
        length = collatz(COL, i)
        if longest < length:
            longest = length
            best = i

    print "collatz( ", best, " ) has length ", longest
