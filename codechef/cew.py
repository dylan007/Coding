t = int(input())
while t>0:
	t = t-1
	s = input().split()
	a = s[0]
	b = s[1]
	x = 0
	y = 0
	for i in range(len(a)):
		if a[i] == '1':
			x = x*10 + 1
	for i in range(len(b)):
		if b[i] == '1':
			y = y*10 + 1
	print(x*y)