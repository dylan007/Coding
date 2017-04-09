T = input()
for t in range(T):
	n,k = map(int,raw_input().split())
	a=n/2
	b=n/2-1
	x = [n]
	print n/2,k
	if k == n/2:
		print "Case #"+str(t+1)+": "+ "1 0"
		continue
	elif k > n/2:
		print "Case #"+str(t+1)+": "+ "0 0"
		continue
	while k>0:
		k -=1
		y = max(x)
		x.remove(y)
		a = y/2
		b = y/2+(y%2-1)
		x.append(a)
		x.append(b)
		print x
	print "Case #"+str(t+1)+": "+ str(max(a,b)) + " " + str(min(a,b))

