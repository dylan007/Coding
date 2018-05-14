def calc(a,b):
	x = (a+b)/2
	y = x-b
	print x
	print y

def testcases(T):
	while T>0:
		a = raw_input()
		b = raw_input()
		a = int(a)
		b = int(b)
		calc(a,b)
		T = T-1

testcases(10)
