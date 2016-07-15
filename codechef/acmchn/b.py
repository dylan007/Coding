t = input()
while t>0:
	t = t-1
	n = input()
	c = 0
	s = map(int,raw_input().split())
	for i in range(n):
		x = s[i]
		if(x== -1):
			c = c+1
	
	c = c-1
	print float(c)/float(2) + float(1)
