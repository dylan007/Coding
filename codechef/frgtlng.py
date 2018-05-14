t = input()
while t>0:
	t = t-1
	n,k = map(int,raw_input().split())
        pr = {}
	s = raw_input().split()
	for i in range(n):
		if s[i] not in pr:
			pr[s[i]] = 0
	for i in range(k):
		qr = raw_input().split(' ')
		for j in range(1,len(qr)):
			if qr[j] in pr:
				pr[qr[j]] += 1
	j = 0
	for i in range(len(s)):
		if(j<(n-1)):
			if pr[s[i]]==0:
				print "NO",
			else:
				print "YES",
		else:
		 	if pr[s[i]]==0:
		 		print "NO"
		 	else:
		 		print "YES"
		j += 1
