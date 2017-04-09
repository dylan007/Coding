T = input()
for t in range(1,T+1):
	x = input()
	ans = 0
	for i in range(1,x+1):
		s = str(i)
		l = "".join(sorted(list(str(i))))
		if s==l:
			ans = i
	print "Case #"+str(t)+": "+str(ans)