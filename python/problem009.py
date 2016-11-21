#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Special Pythagorean Triplet
# 

    
def isPythagorean(a, b, c):

    return a*a + b*b == c*c
    

def tripletGenerator(n):

    for a in range(1, n // 2 + 1):
        b = a
        while b <= n - (a + b): 
            c = n - (a + b)
            yield (a, b, c)
            b += 1

            
if __name__ == "__main__":

    n = 1000
    result = 0
        
    for a,b,c in tripletGenerator(n):
    
        if isPythagorean(a, b, c):  
            print "Pythagorean triplet found: ", (a, b, c)
            result = max(result, a * b * c)
            
    print "max product is equal to ", result

