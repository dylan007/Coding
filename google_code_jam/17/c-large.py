T = input()
for t in range(T):
	n,k = map(int,raw_input().split())
	s = [n]
	c = {}
	c[n] = 1
	ans = 0
	a = 0
	b = 0
	while True:
		x = max(s)
		a = (x/2)
		b = (x/2)+(x%2 - 1)
		ans += c[x]
		if ans >= k:
			break
		else:
			s.remove(x)
			if a not in s:
				s.append(a)
			if b not in s:
				s.append(b)
			if a in c.keys():
				c[a] += c[x]
			else:
				c[a] = c[x]
			if b in c.keys():
				c[b] += c[x]
			else:
				c[b] = c[x]
	print "Case #"+str(t+1)+": "+str(a) + " " + str(b)	