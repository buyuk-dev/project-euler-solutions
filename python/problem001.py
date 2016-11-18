#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# sum of all multiples of 3 or 5 below 1000
#


def sumOfMultiplesOfN(n, limit):

    kmax = limit // n
    return n * (kmax * (kmax + 1) / 2)


if __name__ == '__main__':

    sum3 = sumOfMultiplesOfN(3, 999)
    sum5 = sumOfMultiplesOfN(5, 999)
    sum15 = sumOfMultiplesOfN(15, 999)

    result = sum3 + sum5 - sum15

    print "Sum of multiples of 3 or 5 lower than 1000 is ", result
