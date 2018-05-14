def fact(a):
	pro = 1
	while a >=2:
		pro = pro*a
		a = a-1
	print pro

def testcases(t):
	while t>0:
		a = input()
		fact(a)
		t = t-1

T = input()
testcases(T)
