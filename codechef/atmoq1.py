t = input()
while t>0:
	t = t-1
	s = raw_input()
	l = list(set(s))
	n,k = map(int ,raw_input().split())
	ans = []
	while n>0:
		n = n-1
		q = raw_input()
		x = list(set(q))
		p = list(set(l) & set(x))
		if len(p)>=k:
			ans.append(q)
	if len(ans)>0:
		print "Yes"
		for i in ans:
			print i
	else:
		print "No"