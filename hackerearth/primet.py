def primes(n): 
	if n==2: 
		return [2]
	elif n<2:
		return []
	s=range(3,n+1,2)
	mroot = n ** 0.5
	half=(n+1)/2-1
	i=0	
	m=3
	while m <= mroot:
		if s[i]:
			j=(m*m-3)/2
			s[j]=0
			while j<half:
				s[j]=0
				j+=m
		i=i+1
		m=2*i+3
	return [2]+[x for x in s if x]

t = int(raw_input())
p = primes(5000000)
for i in range(t):
	x,y = raw_input().split(' ')
	x = int(x)
	y = int(y)
	if(x>y):
		t = x
		x = y
		y = t
	ans = 0 
	while (y>=x):
	 	if(y in p):
			ans= ans - y
		else:
		 	ans = ans+y
		y = y/2
	print ans







