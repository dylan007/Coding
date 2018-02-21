def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
 
def count(a,b):
	if a[0] == b[0]:
		return abs(a[1]-b[1])-1
	elif a[1] == b[1]:
		return abs(a[0]-b[0])-1
	return gcd(abs(a[1]-b[1]),abs(a[0]-b[0]))-1
 
def get_center(l):
	x,y = l[0]
	for i in range(1,n):
		x += l[i][0]
		y += l[i][1]
	return (int(x/len(l)), int(y/len(l)))
 
def onSegment(p,q,r):
	if (q[0] <= max(p[0],r[0])) and (q[0] >= min(p[0],r[0])) and (q[1] <= max(p[1],r[1])) and (q[1] >= min(p[1],r[1])):
		return True
	return False
 
def orientation(p,q,r):
	val = (q[1]-p[1])*(r[0]-q[0]) - (q[0]-p[0])*(r[1]-q[1])
	if val==0:
		return 0
	if val>0:
		return 1
	return 2
 
def intersect(p1,q1,p2,q2):
	o1 = orientation(p1,q1,p2)
	o2 = orientation(p1,q1,q2)
	o3 = orientation(p2,q2,p1)
	o4 = orientation(p2,q2,q1)
 
	if (o1 != o2) and (o3 != o4):
		return True;
 
	if (o1==0 and onSegment(p1, p2, q1)):
		return True
 
	if (o2==0 and onSegment(p1, q2, q1)):
		return True
 
	if (o3==0 and onSegment(p2, p1, q2)):
		return True
 
	if (o4==0 and onSegment(p2, q1, q2)):
		return True
 
	return False
 
 
def check(p,l):
	if (len(l) < 3): 
		return False
 
	extreme = (1000000000, p[1])
 
	count = 0
	i = 0
	flag = 0
	n = len(l)
 	while(i!=0 and flag):
 		flag = 1
		nex = (i+1)%n
		if (intersect(l[i], l[nex], p, extreme)):
			if (orientation(l[i], p, l[nex]) == 0):
				if onSegment(l[i], p, l[nex]):
					return 2	
			count+=1
		i = nex
	if count%2 == 1:
		return False
	#if count==0:
	#	return False
	return True
 
def flood(p,l,points,limit,ma):
	if len(points)==limit:
		return
	#print p
	if p in ma.keys():
		return
	ma[p] = 0
	if check((p[0],p[1]),l):
		#print (p[0],p[1])
		points.append((p[0],p[1]))

	flood((p[0]+1,p[1]),l,points,limit,ma)
	flood((p[0]+1,p[1]+1),l,points,limit,ma)
	flood((p[0]+1,p[1]-1),l,points,limit,ma)
	flood((p[0],p[1]),l,points,limit,ma)
	flood((p[0],p[1]+1),l,points,limit,ma)
	flood((p[0],p[1]-1),l,points,limit,ma)
	flood((p[0]-1,p[1]),l,points,limit,ma)
	flood((p[0]-1,p[1]+1),l,points,limit,ma)
	flood((p[0]-1,p[1]-1),l,points,limit,ma)
	return
 
t = input()
while t>0:
	t = t-1
	n = input()
	l = []
	a = 0
	x,y = map(float,raw_input().split())
	l.append((x,y))
	for i in range(n-1):
		x,y = map(float,raw_input().split())
		l.append((x,y))
		a += abs((l[i][0]*l[(i+1)%n][0])*(l[i][1]-l[(i+1)%n][1]))
	a /= 2.0
	b = 0.0
	#print a
	for i in range(n-1):
		b += count(l[i],l[(i+1)%n])
	a += (1-b/2)
	limit = int(n/10)
	points = []
	ma = {}
	flood(get_center(l),l,points,limit,ma)
	#print check()
	for i in range(len(points)):
		print points[i][0],points[i][1] 