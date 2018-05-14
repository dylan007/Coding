n,m = map(int,raw_input().split())
d = {}
i = 1
while i<=n:
	if i==m:
		continue
	else:
		if m<i:
			x = range(m+1,min(n+1,2*i-m))
		else:
			x = range(max(1,i-(m-i)+1),m)
	for j in range(len(x)):
		if x[j] not in d.keys():
			d[x[j]] = 1
		else:
			d[x[j]] += 1
	i += 1
	print i
	print n

d = sorted(d.items(), key=lambda x: x[1], reverse=True)
print d[0][0]
