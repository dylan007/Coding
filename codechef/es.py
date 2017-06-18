#n = long(raw_input())
for i in range(1,10000):
    n = i
    l = [2,7,15,25,38,54,73]
    r = n%7
    q = n/7
    if(r==0):
        s = 73*q + 19*7*(((q-1)*(q))/2)
        print s
    else:
        s = 73*q + 19*7*(((q-1)*(q))/2)
        print s+q*19*r+l[r-1]
