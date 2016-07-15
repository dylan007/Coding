def testcases(T):
	y = T
	s=0
	while T>0:
		x = raw_input()
		x = int(x)
		s = s+x
		T = T-1
	if s%y == 0:
		print 'YES'
	else:
		print 'NO'

T = raw_input()
T = int(T)
while T>0:
	a = raw_input()
	a = raw_input()
	a = int(a)
	testcases(a)
	T = T-1

