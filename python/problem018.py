#
# Copyright (c) 2015 - buyuk.dev@gmail.com
# ----------------------------------------
# https://projecteuler.net/problem=18


filename = raw_input()
tri = []
with open(filename, "r") as fi:
    for line in fi:
        tri.append([int(v) for v in line.split()])



for i,row in enumerate(tri[:-1]):
    temp = [v for v in tri[i+1]]
    for j,v in enumerate(row):
        tri[i+1][j] = max(tri[i+1][j], temp[j]+v)
        tri[i+1][j+1] = max(tri[i+1][j+1], temp[j+1]+v)
       

print max(tri[-1]) 
