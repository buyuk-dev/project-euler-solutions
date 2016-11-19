#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# find the largest palindrome number made
# from the product of two n-digit numbers.
#


def isPalindrome(n):
    
    for beg, end in zip(str(n), reversed(str(n))):
        if beg != end:
            return False
    return True



if __name__ == '__main__':
    
    largest = 0
    for i in range(100, 1000):
        for j in range(i, 1000):
            if isPalindrome(i * j):
                largest = max(i * j, largest)

    print "largest palindrome number in range is ", largest

