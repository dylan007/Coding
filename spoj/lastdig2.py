t = input()
while t>0:
    t = t-1
    a,b = raw_input().split()
    b = long(b)
    if a[0]=="0":
        print "0"
    if b==0:
        print "1"
    else:
        ans = 0
        for i in range(len(a)):
            ans = ans*b + int(b[i])
        print ans
