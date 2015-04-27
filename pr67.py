#!/usr/bin/python
# -*- coding: utf-8 -*-
# Maximum Path Sum II: https://projecteuler.net/problem=67
# Download 'triangle.txt' from the problem page.
# Break it down, bottom-to-up, row by row.

# Read the file and parse integers.
data = []
for l in open('triangle.txt','r').readlines():
    data.append( [int(i) for i in l.split()] )

# Go through the list backwards.
for i, r in reversed(list(enumerate(data))):
    # We will skip the last (or in this case, first) row.
    if i == len(data) - 1:
        continue
    # Calculate the adjacent sums, and pick the larger one.
    for pos, val in enumerate(r):
        left = val + data[i + 1][pos]
        right = val + data[i + 1][pos + 1]
        data[i][pos] = max(left, right)

print "Solution: %d" % data[0][0]
