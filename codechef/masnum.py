def power(x):
	r=1
	t = 10
	while x>0:
		x = x-1
		r = (r << 3)+(r << 1)
	return r



t = input()
while t>0:
	t = t-1
	n = input()
	if(n&1 == 1):
		print "0"
	else:
		x = n >> 1
	 	ans = 9*(power(x-1))
	 	print ans
