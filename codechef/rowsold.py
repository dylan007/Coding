def swap(s,x,y):
	l = list(s)
	l[x],l[y] = l[y],l[x]
	out = ""
	for x in l:
		out += str(x)
	return out

t = input()
while t>0:
	t = t-1
	s = raw_input()
	ans = 0
	while True:
		if '1' not in s:
			break
		x = s.rfind('0')
		y = s.rfind('1')
		if s.find('0')<s.find('1'):
			break
		if x<y:
			s = s[:x+1]			
			continue
		ans += (1+x-y)
		s = swap(s,x,y)
		print s
	print ans
