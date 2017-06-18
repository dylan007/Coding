def ls(a,item,low,high):
    while low<=high:
        if item < a[low]:
            return low-1
        low += 1
    return high

def bs(a,item,low,high):
    if high<=low:
        if(item > a[low]):
            return low+1
        else:
            return low
    mid = (low+high)/2
    if item==a[mid]:
        return mid
    elif item>a[mid]:
        return bs(a,item,mid+1,high)
    return bs(a,item,low,mid-1)


t = input()
while t>0:
    t = t-1
    p,q,r = map(long,raw_input().split())
    a = map(long,raw_input().split())
    b = map(long,raw_input().split())
    c = map(long,raw_input().split())
    a.sort()
    c.sort()
    x = [a[0]]
    for i in range(1,len(a)):
        x.append(a[i]+x[i-1])
    y = [c[0]]
    for i in range(1,len(c)):
        y.append(c[i]+y[i-1])
    ans = 0
    for i in range(len(b)):
        p1 = bs(a,b[i],0,p-1)
        p2 = bs(c,b[i],0,r-1)
        p1 += a.count(b[i])-1
        p2 += c.count(b[i])-1
        if p1>=p:
            p1 = p-1
        if p2>=r:
            p2 = r-1
        if p1>=0:
            p1 -= (a[p1]>b[i])
        if p2>=0:
            p2 -= (c[p2]>b[i])
        #print p1,p2
        if p1>=0:
            s1=x[p1]
        else:
            s1 = 0
        if p2>=0:
            s2=y[p2]
        else:
            s2 = 0
        p1 += 1
        p2 += 1
        #print s1,s2,p1,p2
        ans += ((s1*p2*b[i])+(s2*p1*b[i])+(b[i]*b[i]*p1*p2)+(s1*s2))
    print ans%1000000007

