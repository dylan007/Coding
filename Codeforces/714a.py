l1,r1,l2,r2,k = map(int,raw_input().split())

if l1>r2 or l2>r1:
	print "0"
elif l1<=r2 and l1>=l2:
	x = 0
	if k<=r2 and k>=l1:
		x = 1
	print r2-l1+1-x
else:
	x = 0
	if k<=r1 and k>=l2:
		x = 1 
	print r1-l2+1-x
