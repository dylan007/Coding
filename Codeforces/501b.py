t = int(raw_input())
handls =  {}
for i in xrange(t):
	s,r = raw_input().split(' ');
	handls[s]=r;

for key in handls:
	for key1 in handls:
		if handls[key]==key1:
			handls[key]=handls[key1]
			del handls[key1]

print len(handls)
