def fact(n):
    if n==0:
    	return 1
    return n*fact(n-1)

def nCr(n,r):
    return fact(n)/(fact(n-r)*fact(r))

t = input()
while t>0:
	t = t-1
	x = input()
	ans = nCr(3+x-1,2)
	print ans
