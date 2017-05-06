import sys
n,k,p = map(int,raw_input().split())
x = map(int,raw_input().split())
q = raw_input()
for i in range(len(q)):
    if q[i] == "!":
        temp = x[-1:] + x[:-1]
        x = temp[:]
    else:
        if k>=n:
            print sum(x)
            continue
        ans = 0
        for i in range(n-k+1):
            ans = max(ans,sum(x[i:i+k]))
        print ans
    
