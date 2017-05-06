t = input()
while t>0:
    t = t-1
    n = input()
    s = map(int,raw_input().split())
    print n-max(s)
