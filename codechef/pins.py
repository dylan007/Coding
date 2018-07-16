def power(n):
	ans = 1
	x = 10
	while n>0:
		if (n%2) == 1:
			ans *= x
		x = x*x
		n //= 2
		# print(n)
	return ans

t = int(input())
while t>0:
	n = int(input())
	c = n//2 + n%2
	n -= c
	# print(n)
	print("1",power(n))
	t = t-1