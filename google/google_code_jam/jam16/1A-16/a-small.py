T = input()
for t in range(T):
	t = t-1
	s = raw_input()
	out = ""
	for i in range(len(s)):
		x = s[i]
		if len(out)==0:
			out += x 
			continue
		if x>=out[0]:
			out = x+out
		else:
			out += x
	print "Case #"+str(t+2)+": "+out