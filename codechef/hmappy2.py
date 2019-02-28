def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

t = int(input())
while t>0:
	t = t - 1
	n,a,b,k = map(int,input().split())
	g = (a*b)/gcd(a,b)
	c = (n//a) + (n//b) - 2*(n//g)
	if c>=k:
		print("Win")
	else:
		print("Lose")