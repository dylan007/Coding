t,s,x = map(int,raw_input().split())
if x<t:
	print "NO"
else:
	x = x-t
	if x<s:
		if x==0:
			print "YES"
		else:
			print "NO"
	else:
		x = x%s
		if x==0 or x==1:
			print "YES"
		else:
			print "NO"
