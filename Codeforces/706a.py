def dist(x,y,a,b):
	return ((x-a)**2 + (y-b)**2)**0.5



x,y = map(float,raw_input().split())

t = input()
m = 100000000
while t>0:
	t = t-1
	a,b,c = map(float,raw_input().split())
	m = min(m,dist(x,y,a,b)/c)
print "%.6f"%m
