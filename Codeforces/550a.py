import sys,re

s = raw_input()
inds = [x.start() for x in re.finditer('AB', s)]
for i in range(len(inds)):
	x = s[:inds[i]]
	y = s[inds[i]+2:]
	if x.find("BA") >= 0 or y.find("BA")>=0:
		print "YES"
		sys.exit(0)
	
print "NO"
