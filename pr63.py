count = 0;
for a in range(1, 100, 1):
    for b in range(1, 100, 1):
        if(len(str(a**b)) == b):
            count += 1;

print ">",count;
