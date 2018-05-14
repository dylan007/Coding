def hash(x):
    ans = long(0)
    for i in range(len(x)):
        ans += 2**x[i]
    return ans


t = input()
while t>0:
    t = t-1
    n,k = map(long,raw_input().split())
    h = []
    m = hash(range(1,k+1))
    for i in range(n):
        s = map(long,raw_input().split())
        h.append(hash(s[1:]))
    count = 0
    for i in range(n):
        for j in range(i+1,n):
            if h[i]+h[j] >= m:
                count += 1
    print count
