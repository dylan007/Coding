n,m = map(int,raw_input().split())
d = {}
for i in range(n):
	name,ip = raw_input().split()
	d[ip] = name
for i in range(m):
	comm,ip = raw_input().split()
	ip = ip[:-1]
	print comm + " " + ip + "; #" + d[ip] 
