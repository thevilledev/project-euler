#!/usr/bin/python

def fact(n):
    if(n <= 0):
        return 1;
    else:
        return n*fact(n-1);

print sum(int(i) for i in str(fact(100)))
