#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# compute sum(i^2, i=1..N) - sum(i = 1..N)^2
#


N = 100


def sumOfSquares(lim):

    result = 0    
    for i in range(1, lim + 1):
        result += i * i
    
    return result


def squareOfSum(lim):

    s = lim * (lim + 1) / 2
    return s * s


if __name__ == '__main__':

    diff = squareOfSum(N) - sumOfSquares(N)
    print "Difference between square of sum and sum of squares is ", diff
    
