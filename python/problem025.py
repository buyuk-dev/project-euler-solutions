import math

def bruteforce(ndigits):
    a, b, i = 1, 1, 2
    while len(str(b)) < ndigits:
        i += 1
        c = a + b
        a = b
        b = c
    return b, i

def estimate(ndigits):
    phi = (1.0 + math.sqrt(5.0)) / 2.0
    lp = math.log(phi, 10)
    k = 1
    while math.floor(lp * k - math.log(math.sqrt(5), 10)) + 1 < ndigits:
        k += 1

    return math.ceil(lp * k) + 1, k

print(bruteforce(1000))
print(estimate(1000))
    
