import sys

n,k = map(int,raw_input().split())
s = raw_input()

if abs(s.find("G") - s.find("T")) < k:
	print "NO"
	sys.exit(0)

if s.find("T")>s.find("G"):
	s = s[s.find("G"):s.find("T")+1]
	pos = 0
	while s[pos]!="T":
		if s[pos+k] == "." or s[pos+k]=="T":
			pos = pos+k
			if pos >= len(s):
				pos = len(s)-1
				break
		else:
			break

	if s[pos]=="T":
		print "YES"
	else:
		print "NO"
else:
	s = s[s.find("T"):s.find("G")+1]
	pos = len(s)-1
	while s[pos]!="T":
		if s[pos-k] == "." or s[pos-k]=="T":
			pos = pos-k
			if pos<0:
				pos = 0
				break
		else:
			break
	if s[pos]=="T":
		print "YES"
	else:
		print "NO"
	
