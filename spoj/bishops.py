from sys import stdin

for line in stdin:
    x = long(line)
    if x==1:
        print 1
    else:
        print 2*x-2

