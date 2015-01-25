def factorial(n):
    if(n <= 0):
        return 1;
    else:
        return n*factorial(n-1);

count = 0;

for n in xrange(101):
    for r in xrange(n+1):
        up = factorial(n);
        down = factorial(r)*factorial(n-r);
        if(up/down > 1000000):
            count += 1;

print ">",count;
