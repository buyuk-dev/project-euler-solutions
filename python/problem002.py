#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Sum even Fibonacci numbers <= 4 000 000
#

def evenFibSum(n):
    a = 0
    b = 2
    s = 0
    
    while b <= n:
        tmp = a
        a = b
        b = 4 * b + tmp
        s += a

    return s


if __name__ == '__main__':

    n = 4000000

    result = evenFibSum(n)

    print "sum of even Fibonacci numbers lower than or equal ", n, " is ", result
