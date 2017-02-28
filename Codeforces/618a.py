x = input()
l = []
for i in range(x):
	l.append(1)
	if len(l)>1:
		while l[-1]==l[-2]:
			x = l[-1]+1
			l = l[:-2]
			l.append(x)
			if len(l)==1:
				break
for i in range(len(l)):
	print l[i],
