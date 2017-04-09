t = input()
while t > 0:
	t = t-1
	q,k = map(int,raw_input().split())
	c = {}
	for i in range(1,k+1):
		c[i] = 0
	flag = 0
	for i in range(q):
		x = map(int,raw_input().split())
		y = list(set(x[1:]))
		if len(y) == k:
			flag=3
		for i in y:
			c[i] += 1
	if flag==3:
		print "some"
		continue

	flag=3
	for i in range(1,k+1):
		if c[i]==0:
			flag=1
		elif c[i]==1:
			flag=2
	if flag==1:
		print "sad"
	elif flag==2:
		print "all"
	else:
		print "some"