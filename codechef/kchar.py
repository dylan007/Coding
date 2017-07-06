import math


def calc(x,y):
    l = y/2
    if(y==1):
        return 0
    if(x==l or x==0):
        return 0
    elif x<l:
        return calc(x,l)
    else:
        return 1-calc(2*l-x,l)


t = input()
while t>0:
    t = t-1
    x = long(input())
    if x==1:
        print "a"
        continue
    y = long(math.ceil(math.log(x+1,2)))
    y = 2**y - 1
    x -= 1
    print x,y
    if calc(x,y)==0:
        print "a"
    else:
        print "c"
