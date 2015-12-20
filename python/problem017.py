#
# Copyright (c) 2015 - buyuk.dev@gmail.com
# ----------------------------------------
# https://projecteuler.net/problem=17
#


num = [None] * 1001
num[0] = "zero"
num[1] = "one"
num[2] = "two"
num[3] = "three"
num[4] = "four"
num[5] = "five"
num[6] = "six"
num[7] = "seven"
num[8] = "eight"
num[9] = "nine"
# ----------------
num[10] = "ten"
num[20] = "twenty"
num[30] = "thirty"
num[40] = "forty"
num[50] = "fifty"
num[60] = "sixty"
num[70] = "seventy"
num[80] = "eighty"
num[90] = "ninety"
# ----------------
num[1000] = "thousand"


for dec in range(10, 100, 10):
    for unit in range(1, 10):
        num[dec + unit] = num[dec] + "-" + num[unit]

num[11] = "eleven"
num[12] = "twelve"
num[13] = "thirteen"
num[14] = "fourteen"
num[15] = "fifteen"
num[16] = "sixteen"
num[17] = "seventeen"
num[18] = "eighteen"
num[19] = "nineteen"

for hun in range(100, 1000, 100):
    for dec in range(0, 100):
        num[hun + dec] = num[hun/100] + " " + "hundred"
        if dec > 0:
            num[hun + dec] += " and " + num[dec]

num[1000] = "one thousand"


def count(ns):
    return len([s for s in ns if s not in " -"])


sum = 0
for i in range(1, 1001):
    sum += count(num[i])

print sum



