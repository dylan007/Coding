check = 'machula'
def testcases(T):
	while T>0:
		acas = raw_input()
		a = raw_input().split(' ')
		if check in a[0]:
			x = int(a[2])
			y = int(a[4])
			print repr(y-x)+' + '+a[2]+' = '+a[4]
		elif check in a[2]:
			x = int(a[0])
			y = int(a[4])
			print a[0]+' + '+repr(y-x)+' = '+a[4]
		elif check in a[4]:
			x = int(a[0])
			y = int(a[2])
			print a[0]+' + '+a[2]+' = '+repr(x+y)
		T = T-1

t = raw_input()
t = int(t)
testcases(t)
