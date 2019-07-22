def factorial(n):
     ''' Compute n!
     '''
     if n == 0: return 1
     return factorial(n-1) * n


def factorialization(n):
     ''' f(n) = X : (sum(x!) for each x in X) == n.
     '''
     k = 1
     while factorial(k) < n:
         k += 1

     factors = []
     while k > 0:
         k -= 1
         a = n // factorial(k)
         b = n - a * factorial(k)
         factors.append(a)
         n = b

     return factors


def nth_permutation(s, n):
     ''' return n-th lexicographic permutation of s elements <0..s)
     '''
     S = [i for i in range(s)]
     p = []

     for x in factorialization(n - 1):
         p.append(S[x])
         del S[x]

     return p


print(nth_permutation(10, 1000000))
