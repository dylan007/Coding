def gcd(a,b):
	if b==0 :
		return a
	else:
		return gcd(b,a%b)

def testcases(n):
	while n>0:
		a,b = raw_input().split()
		a = int(a)
		b = int(b)
		c = gcd(a,b)
		print c
		n = n-1

N = input()
testcases(N)
