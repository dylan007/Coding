def nCr(n,k):
    ans = 1
    for i in range(n,n-k,-1):
        ans *= i
    for i in range(1,k+1):
        ans /= i
    return ans

n = input()
s = map(int,raw_input().split())
s.sort()
x = s[:]
y = s[:3]
s = list(set(y))
ans = 1 
#print x,y,s
#print x.count(s[0]),y.count(s[0])
for i in range(len(s)):
    ans *= nCr(x.count(s[i]),y.count(s[i]))
print ans
