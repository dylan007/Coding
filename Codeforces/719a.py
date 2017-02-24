t = input()
s = map(int,raw_input().split())

if t == 1:
	if s[t-1] == 15:
		print "DOWN"
	elif s[t-1] == 0:
		print "UP"
	else:
		print "-1"
else:
	if s[t-1] > s[t-2] : 
		if s[t-1]!=15:
			print "UP"
		else:
			print "DOWN"
	else:
		if s[t-1]==0:
			print "UP"
		else:
			print "DOWN"

