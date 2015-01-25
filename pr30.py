def getProduct(n):
    product = 0;
    for i in xrange(len(str(n))):
        product += int(str(n)[i])**5;
    return product;

sum = 0;

for i in xrange(2, 200000):
    if(getProduct(i) == i):
        sum += i;

print "> ",sum
