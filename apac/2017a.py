t = input()

for j in range(t):
	n = input()
	s = {}
	ind = 0
	for i in range(n):
		x = raw_input().strip(' ')
		l = len(list(set(x)))
		if l in s.keys():
			if x < s[l]:
				s[l] = x
		else:
			s[l] = x
		ind = max(l,ind)
	print "Case #" + str(j+1) + ":",
	print s[ind]
