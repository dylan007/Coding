import math 
e = math.exp(1)
for i in range(1,10000):
    print i,long(e*i)-long(e*(i-1))

