digsum = 0
for a in range(90, 100, 1):
    for b in range(90, 100, 1):
        tmpsum = 0; pwr = str(a**b);
        for i in range(len(pwr)):
            tmpsum += int(pwr[i])
        if(tmpsum > digsum):
            digsum = tmpsum

print "> " + str(digsum)
