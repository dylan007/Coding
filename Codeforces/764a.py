def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

n,m,z = map(int,raw_input().split())
print z/((n*m)/gcd(n,m))
