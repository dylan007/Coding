t = input()
while t>0:
    t = t-1
    n,s = map(long,raw_input().split())
    arr = map(long,raw_input().split())
    arr.sort()
    x = 0
    ans = -1
    for i in range(n):
        p = s-x
        q = n-i
        if(p%q == 0):
            if i==0:
                if (p/q)<=arr[i]:
                    ans = p/q
                    break
            else:
                if (p/q)<=arr[i] and (p/q)>=arr[i-1]:
                    ans = p/q
                    break
        x += arr[i]
    print ans
