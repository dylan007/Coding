def modexp(x,p):
	ans = 1
	while p>0:
		if (p%2) == 1:
			ans = (ans * x)%1000000007
		x = (x*x)%1000000007
		p = p//2
	return ans

s = input()
x,k = map(int,s.split())
mod = 1000000007
if(x==0):
	print(0)
else:
	print(((modexp(2,k+1) * x)%mod - (modexp(2,k)-1))%mod)