#!/usr/bin/python

answer = 0;
f = open('lulz', 'r');
for line in f:
    answer += int(line);
print "> ",str(answer)[:10]
