t = input()
while t>0:
	t = t-1
	a = raw_input().split()
	b = raw_input().split()
	c = []
	for x in a:
		if x in b:
			c.append(x)
	if len(c)>=2:
		print "similar"
	else:
		print "dissimilar"