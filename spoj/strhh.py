t = input()
while t>0:
	t = t-1
	s = raw_input()
	print "".join(list(s)[:len(s)/2][0::2])
