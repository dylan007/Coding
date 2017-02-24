n,k = map(int,raw_input().split())
s = map(int,raw_input().split())
ans = 0
for i in range(1,n-1):
	x = s[i]
	s[i] = max(s[i],max(k-s[i-1],k-s[i+1]))
	ans += (s[i]-x)

if s[n-1]+s[n-2] < k:
	x = s[n-1]
	s[n-1] = k-s[n-2]
	ans += (s[n-1]-x)

print ans
for i in range(n):
	print s[i],
