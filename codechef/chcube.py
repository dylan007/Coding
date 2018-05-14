t = input()
while t>0:
	sides = raw_input().split(' ')
	x = 0
#	0:front 1:back 2:left 3:right 4:top 5:bottom
	x |= (sides[0]==sides[2] and sides[2]==sides[5])
	x |= (sides[0]==sides[3] and sides[3]==sides[5])
	x |= (sides[0]==sides[2] and sides[2]==sides[4])
	x |= (sides[0]==sides[3] and sides[3]==sides[4])
	x |= (sides[0]==sides[3] and sides[3]==sides[4])
	x |= (sides[1]==sides[3] and sides[3]==sides[4])
	x |= (sides[0]==sides[3] and sides[3]==sides[5])
	x |= (sides[1]==sides[3] and sides[3]==sides[5])	
	x |= (sides[1]==sides[2] and sides[2]==sides[4])	
	x |= (sides[1]==sides[2] and sides[2]==sides[5])
	if(x == 1):
		print "YES"
	else:
	 	print "NO"
	t = t-1
