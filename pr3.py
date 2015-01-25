def isprime(n):
    if (n < 2):
        return False;
    if (n == 2):
        return True;
    elif (n % 2 == 0):
        return False;
    for x in range(3, int(n**0.5)+1, 2):
        if(n % x == 0):
            return False;
    return True;

MAX = 600851475143;
res = 0;

for num in range(1, int(MAX**0.5), 1):
    if ((MAX % num == 0) and isprime(num) and (num > res)):
        res = num;

print "> ",res
