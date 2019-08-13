import math

t = int(input())
while t>0:
    t = t-1
    n = int(input())
    k = list(map(float,input().split()))
    c = list(map(float,input().split()))
    nd = float(n)
    flag = 1
    s = (k[0] > 0.0)
    d = 0.0
    for i in range(n):
        d += c[i] * k[i]
    for i in range(n):
        if(s!=(k[i]>0)):
            flag=0
            break
    if(s!=(d>=0)):
        flag=0
    if(flag==0):
        print(-1)
        continue
    if not s:
        for i in range(n):
            k[i] *= -1
        d *= -1
    val = 1.0
    num = 0.0
    for i in range(n):
        val *= k[i]
        num += (1/k[i])
    num = num * val
    x1 = (d*val/num)
    ans = []
    for i in range(n):
        ans.append(1/(k[i] * k[i]))
    f = 0.0
    f = (num/val) * math.sqrt(x1)
    print("{0:.10f}".format(f),end=" ")
    for i in range(n):
        print("{0:.10f}".format((x1/(k[i]*k[i]))-c[i]),end=" ")
    print('')
