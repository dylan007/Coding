def testcases(T):
	while T>0:
		a = raw_input().split(' ')
		a[0] = a[0][::-1]
		a[1] = a[1][::-1]
		x = int(a[0])
		y = int(a[1])
		ans = repr(x+y)
		ans = ans[::-1]
		ans = int(ans)
		print ans
		T = T-1

t = raw_input()
t = int(t)
testcases(t)
