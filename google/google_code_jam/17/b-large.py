T = input()
for t in range(T):
	s = list(raw_input())
	if s == sorted(s):
		print "Case #"+str(t+1)+": "+ "".join(s)
		continue
	i = len(s)
	while True:
		x = 0
		while s[x] <= s[x+1]:
			x += 1
		s[x] = chr(ord(s[x])-1)
		s[x+1:] = ["9"]*(i-x-1)
		if s==sorted(s):
			print "Case #"+str(t+1)+": " + str(long("".join(s)))
			break