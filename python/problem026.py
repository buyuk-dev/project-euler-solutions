# From the Little Fermat Theorem
# Based on the fact that: (1 / D * 10 ^ c) - floor(1 / D * 10^c) == 1 / D
# which can be rewritten as: (10^c - 1) / D == floor(1 / D * 10^c)
# This means that (10^c - 1) / D must be an integer, so: 10^c mod D == 0
# So out of all D values, we need to find one that implies the greatest smallest value of c
# that fits the equation 10^c mod D == 0
# ---------------------------------------
# 10**c mod D == 1 --> find D : max min c

def prime_sieve(n):
    P = [i for i in range(2, n+1)]
    i = 0
    while i*i <= n:
        P = [p for p in P if P[i] == p or p % P[i] != 0]
        i = i + 1
    return P

def find_length(d):
    c = 1
    if d < 8: return 3
    # this could be rewritten without using bigint powers.
    # we can use the fact that: (a*b) mod n = (a mod n * b mod n) mod n
    # store the result of the previous modulo and use it to calculate the next step.
    while (10 ** c) % d != 1:
        c = c + 1
    return c

best_length, best_d = 0, 0
for d in prime_sieve(1000):
    length = find_length(d)
    if length > best_length:
        best_length = length
        best_d = d

print(best_d, best_length)




