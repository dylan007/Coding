def gcd(a,b):
	while b:
		a,b = b,a%b
	return a

t = int(raw_input())
for i in range(t):
	x,y = raw_input().split(' ')
	x = long(x)
	y = long(y)
	if(gcd(x,y)==1):
		print 'Is a Co-Prime'
	else:
	 	print 'Not a Co-Prime'
