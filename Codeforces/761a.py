import sys

x,y = map(int,raw_input().split())
if x==0 and y==0:
	print "NO"
	sys.exit(0)
if abs(x-y)<=1:
	print "YES"
else:
	print "NO"
