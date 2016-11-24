#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# Lattice paths
#


def loadData(filename):

    data = 0
    with open(filename, "r") as dataFile:

        line = dataFile.readline()
        data = int(line)

    return data


def computeNumberOfPaths(size):

    res = 1
    for i in range(1, size + 1):
        res = (res * (size + i)) // i

    return res


if __name__ == '__main__':

    size = loadData("data/problem015.dat")
    
    result = computeNumberOfPaths(size)

    print "number of different paths in ", size, "x", size, " lattice is ", result

