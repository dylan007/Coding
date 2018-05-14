T = input()
for t in range(T):
	x = input()
	a = map(int,raw_input().split())
	b = map(int,raw_input().split())
	a.sort()
	b.sort()
	b = b[::-1]
	ans = 0
	for i in range(x):
		ans += a[i]*b[i]
	print "Case #"+str(t+1)+": "+str(ans)