#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Highly divisible triangular number
#


def divisors(n):
''' TODO: optimize this method using prime factorization
'''
    divs = 0

    for d in range(1, n+1):
        if n % d == 0:
            divs += 1

    return divs



def tridivs(D, n):

    if n % 2 == 0:
        return D[n // 2] * D[n + 1]

    else:
        return D[(n + 1) // 2] * D[n]



def precomputeDivisors(beg, end):

    D = [-1]

    for n in range(beg, end):
        divs = divisors(n)
        print n, " has ", divs, " divisors."
        D.append(divs)

    return D



if __name__ == '__main__':

    D = precomputeDivisors(1, 50000)   
 
    lim = 500
    d = n = 1

    while d < lim and n + 1 < len(D):
        d = tridivs(D, n)
        print "T[", n, "] has ", d, " divisors."
        n += 1
        
    n -= 1
    print (n * n + n) // 2


