n,m = map(int,raw_input().split())
if n<m:
	if m-n == 1:
		print "Dr. Chaz will have " + str(m-n) + " piece of chicken left over!"
	else:
		print "Dr. Chaz will have " + str(m-n) + " pieces of chicken left over!"
		
else:
	if n-m == 1:
		print "Dr. Chaz needs " + str(n-m) + " more piece of chicken!"
	else:	
		print "Dr. Chaz needs " + str(n-m) + " more pieces of chicken!"
