#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# largest product i a grid
#

from collections import namedtuple
Point = namedtuple('Point', 'x y')


def readData(filename):
    
    grid = []
    seqlen = 0
    
    with open(filename, "r") as dataFile:
        seqlen = int(dataFile.readline())
        for line in dataFile:
            grid.append([int(cell) for cell in line.split()])
    
    return (seqlen, grid)


def inRange(point, grid):
    
    size = len(grid)
    return (point.x >= 0 and point.y >= 0 and 
            point.x < size and point.y < size)


def product(grid, point, dir, len):
    
    prod = 1
    for i in range(len):
        prod *= grid[point[0]][point[1]]
        point = Point(point.x + dir.x, point.y + dir.y)
        
    return prod


    
if __name__ == "__main__":

    filename = "data/problem011.dat"
    
    seqlen, grid = readData(filename)
    size = len(grid)
    
    dirs = [Point(-1, -1), Point(-1, 0), Point(-1, 1), Point(0, -1), 
            Point(0, 1), Point(1, -1), Point(1, 0), Point(1, 1)]

    maxprod = 0
    for x in range(size):
        for y in range(size):
            for d in dirs:
                lim = Point(x + d.x * seqlen, y + d.y * seqlen)
                if inRange(lim, grid):
                    prod = product(grid, Point(x, y), d, seqlen)
                    maxprod = max(maxprod, prod)
                    
    print "max product of length ", size, " is equal to ", maxprod
    

