#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# find the smallest number evenly
# divisible by all numbers in range 1..N
#


upperBound = 20

# primes vector should contain all prime
# numbers which are less than or equal N
primes = [2,3,5,7,11,13,17,19]



def greatestPowerInRange(base, lim):
    
    val = base
    while val * base <= lim:
        val *= base
    
    return val


if __name__ == '__main__':

    result = 1    
    for p in primes: 
        result *= greatestPowerInRange(p, upperBound)
 
    print "Smallest number evenly divisible by all numbers in range 1..", upperBound, " is ", result
        
        
        
