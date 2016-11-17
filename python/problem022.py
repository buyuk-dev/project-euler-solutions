#
# Copyright (c) 2016 - buyuk.dev@gmail.com
# ----------------------------------------
# total sum of names scores from file
#

filename = "data/problem022.dat";
inputFile = open(filename, "r")


def alphaval(name):
    counter = 0
    for c in name:
        counter += ord(c) - ord('A') + 1
    return counter


def score(name, pos):
    return alphaval(name) * pos


def load(filename):
    return inputFile.read().replace('"', "").split(",")


if __name__ == '__main__':

    names = load(filename)
    names.sort()

    total = 0
    for id, name in enumerate(names):
        total += score(name, id+1) 

    print total
