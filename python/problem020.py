#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# sum all digits in 100!
#

n = 100

def factorial(x):
   if x == 0:
      return 1
   return x * factorial(x - 1)
   
s = sum([int(d) for d in str(factorial(n))])

print("sum of digits in 100! is " + str(s))