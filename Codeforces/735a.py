import sys

n,k = map(int,raw_input().split())
s = raw_input()
x = s.index("G")
y = s.index("T")
if x>y:
	s = s[y:x+1]
	s = s[::-1]
else:
	s = s[x:y+1]

x = s.index("G")
y = s.index("T")

if (x-y)%k == 0:
	flag = 0
	for i in range(x,y+1,k):
		if s[i] == "#":
			flag=1
			break
	if flag==1:
		print "NO"
	else:
		print "YES"
else:
	print "NO"