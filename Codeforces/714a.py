l1,r1,l2,r2,k = map(int,raw_input().split())

if l1>r2 or l2>r1:
	print "0"
elif l1<=r2 and l2>=l1:
	x = 0
	y = 0
	if r2%k == 0:
		x = 1
	if l1%k == 0:
		y = 1
	print r2-l1+1-(r2/k)+(l1/k)-x+y
else:
	x = 0
	y = 0
	if r1%k==0:
		x = 1
	if l2%k==0:
		y = 1
	print r1-l2+1-(r1/k)+(l2/k)-x+y
