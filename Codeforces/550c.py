import sys

s = raw_input()
for i in range(len(s)):
	x = s[:i]+s[i+1:]
	if(int(x)%8 == 0):
		print "YES"
		print x
		sys.exit(0)
print "NO"
