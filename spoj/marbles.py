t = input()
while t>0:
    t = t-1
    a,b = map(long,raw_input().split())
    a -= 1
    b -= 1
    x = 1
    y = 1
    for i in range(b):
        x *= a
        y *= b
        a -= 1
        b -= 1
    print x/y
