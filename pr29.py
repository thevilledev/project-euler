#!/usr/bin/python

numerot = set()

for a in range(2, 101, 1):
    for b in range(2, 101, 1):
        numerot.add(pow(a, b))

print len(numerot)
