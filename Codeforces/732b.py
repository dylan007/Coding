n,k = map(int,raw_input().split())
s = map(int,raw_input().split())
ans = 0
for i in range(1,n):
	ans += max(0,k-s[i]-s[i-1])
	s[i] = max(s[i],k-s[i-1])


print ans
for i in range(n):
	print s[i],

