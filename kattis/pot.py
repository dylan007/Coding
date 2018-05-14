t = input()
ans = 0
while t>0:
	t = t-1
	x = input()
	y = x%10
	x =  x/10
	ans = (ans + x**y)%1000000000
print ans
