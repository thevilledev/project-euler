#!/usr/bin/python

import sys
from math import sqrt
import decimal

summa = 0

for luku in xrange(100):
    a = int(sqrt(luku));
    if(a*a != luku):
        decimal.getcontext().prec = 102;
        b = decimal.Decimal(luku);
        b = b.sqrt();
        summa += sum([int(x) for x in list(str(b)) if x != '.'][0:100]);
print ">",summa;
