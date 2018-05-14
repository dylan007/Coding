import sys
n,k = map(int,raw_input().split())
l = []
for i in range(k):
	x = input()
	l.append(x)
for i in range(1,n+1):
	if i not in l:
		print i
		sys.exit(0)
		break
print "too late"
