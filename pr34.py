MAX = 100000
ratkaisut = []

def factorial(x):
    if(x <= 0):
        return 1;
    else:
        return x*factorial(x-1);

for luku in range(10, MAX, 1):
    summa = 0
    for i in xrange(len(str(luku))):
        summa += factorial(int(str(luku)[i]));
    if(summa == luku):
        ratkaisut.append(luku);

print ">",sum(int(i) for i in ratkaisut);
