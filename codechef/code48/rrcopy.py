def testcases(T):
	while T>0:
		n = raw_input()
		n = int(n)
		a = raw_input().split()
		c = 0
		b = []
		for i in range(n):
			a[i] = int(a[i])
			if a[i] not in b:
				b.append(a[i])
				c = c+1
		print c
		T = T-1

t = raw_input()
t = int(t)
testcases(t)
