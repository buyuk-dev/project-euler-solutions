# quadratic primes
#
# n*n + a*n + b, find a,b which produces the longest sequence of prime numbers for 
# the consecutive values of n = 0, 1, ...
#
# b has to be a prime number, due to the n = 0 term.
#

MAX = 100000
A_RANGE = -1000, 1001
B_RANGE = -1000, 1001


def next(v):
    n = 0
    while n < len(v):
        if v[n]: yield n
        n += 1


def prime_sieve(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    
    for p in next(is_prime):
        for x in range(p+p, n+1, p):
            is_prime[x] = False

    return is_prime


_is_prime = prime_sieve(MAX + 1)
def is_prime(n):
    if n < 0: return False
    return _is_prime[n]


L, A, B = 0, 0, 0
for b in range(*B_RANGE):
    if not is_prime(b):
        continue

    for a in range(*A_RANGE):
        n = 1
        while is_prime(n*n + n*a + b):
            n += 1

        if n > L:
            L, A, B = n, a, b


print(A*B)

