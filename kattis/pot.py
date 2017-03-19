t = input()
ans = 0
while t>0:
	t = t-1
	x = raw_input()
	y = int(x[-1])
	x =  long(x[:-1])
	ans += x**y
print ans
