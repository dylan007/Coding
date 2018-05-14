t = input()
while t>0:
    t = t-1
    n = input()
    s = map(int,raw_input().split())
    s.sort()
    x = s[n:]
    print x[n/2]
    for i in range(n):
        print s[i],s[i+n],
    print ""
