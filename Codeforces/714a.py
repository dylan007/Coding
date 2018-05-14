l1,r1,l2,r2,k = map(int,raw_input().split())
l = max(l1,l2)
r = min(r1,r2)
x = (k>=l) and (k<=r)
if x:
	print max(r-l, 0)
else:
	print max(0,r-l+1)