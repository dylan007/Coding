import math

t = input()
while t>0:
	t -= 1
	x = input()
	ans = long(0)
	i = 1
	while i<=x:
		d = math.log(i,2)
		if (int(d)== d):
			ans -= long(i)
		else:
			ans += long(i)
		i += 1
	print ans
