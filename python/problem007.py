#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Compute n-th prime number
# TODO: How to estimate scale factor?
# 

from math import sqrt
from math import log
from math import e

def genPrimes(lim):

    P = [i for i in range(2, lim)]

    x = 0
    while P[x] <= sqrt(lim):

        P = [f for f in P if (f % P[x] != 0 or f == P[x])]
        x += 1

    return P

    

if __name__ == "__main__":

    n = 10001
    scale = 1.2
    
    lim = int(n * scale * log(n, e))
    P = genPrimes(lim)

    print P[n - 1]
    

