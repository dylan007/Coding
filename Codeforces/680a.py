s = map(int,raw_input().split())
d = list(set(s))
x = sum(s)
ans = sum(s)
for i in range(len(d)):
	if s.count(d[i])>=2:
		ans = min(ans,x-d[i]*min(s.count(d[i]),3))
print ans
