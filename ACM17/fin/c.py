t = input()
while t>0:
    t = t-1
    n,k = map(float,raw_input().split())
    ans = 2*(k*n - n+1)
    ans /= k
    print round(ans,10)

