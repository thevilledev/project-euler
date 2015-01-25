def lychrel(number):
    for i in xrange(50):
        number += int(str(number)[::-1]);
        if(number == int(str(number)[::-1])):
            return False;
    return True;

print sum(lychrel(num) for num in xrange(10, 10000));