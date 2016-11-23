#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Large sum
#

def load(filename):

    data = []
    with open(filename, "r") as dataFile:
        for line in dataFile:
            num = int(line)
            data.append(num)
    return data



if __name__ == '__main__':

    data = load("data/problem013.dat")
    s = sum(data)

    result = str(s)[0:10]

    print result
