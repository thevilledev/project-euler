a, b = 0, 1
counter = 1

while(True):
    if(len(repr(b)) > 1000):
        print ">",counter
        break
    a, b = b, a+b
    counter += 1
