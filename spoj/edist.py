t = input()
while t>0:
    t = t-1
    a = list(raw_input())
    b = list(raw_input())
    p = [item for item in b if item in a]
    print len(b)-len(p)+max(0,len(a)-len(b))
