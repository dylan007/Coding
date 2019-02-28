def ro(x,r):
	p = float(x)/float(r)
	p = round(p)
	vals = []
	i = p
	print x,r
	if i==0:
		i+=1
	while True:
		l = i*r
		d = abs(x-l)
#		print d,l,float(d)/float(l)
		if float(d)/float(l) <=0.1:
			vals.append(int(i))
		else:
			break
		i+=1
	i = p-1
	while True:
		if i==0:
			break 
		l = i*r
		d = abs(x-l)
#		print d,l,float(d)/float(l)
		if float(d)/float(l) <=0.1:
			vals.append(int(i))
		else:
			break
		i-=1
	return vals

T = input()
for t in range(1,T+1):
	n,p = map(int,raw_input().split())
	r = map(int,raw_input().split())
	c = []
	for i in range(n):
		x = map(int,raw_input().split())
		y = []
		for j in range(p):
			y.append(ro(x[j],r[i]))
		c.append(y)
	print "Case #"+str(t)+":",
	ans = 0
	x = c[0]
	print c
	if n==1:
		print len(c)
	else:
		for i in range(len(x)):
			# co = 0
			# flag=True
			# for j in range(1,n):
			# 	if x[i] not in c[j]:
			# 		flag=False
			# 		break
			# 	co += c[j].count(x[i])
			# ans += co
			for j in range(len(x[i])):
				for k in range(1,n):
					for p in range(len(c[k])):
						for q in range(len())	
		print ans