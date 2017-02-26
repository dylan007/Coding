t = input()
s = map(int,raw_input().split())

d = []

S = list(set(s))

for i in range(max(S)+1):
	if i in S:
		d.append(s.count(i)*i)
	else:
		d.append(0)

n = max(S)


l = [0]*(n+1)

l[1] = d[1]

for i in range(2,n+1):
	l[i] = max(l[i-1],l[i-2]+d[i])
print l[n]

"""d = sorted(d.items(),key=lambda x:x[1],reverse=True)
x = {}
for i in range(len(d)):
	x[d[i][0]] = d[i][1]

for i in range(len(d)):
	ans += x[d[i][0]]
	if x[d[i][0]] == 0:
		continue
	if d[i][0]-1 in x.keys():
		x[d[i][0]-1] = 0
	if d[i][0]+1 in x.keys():
		x[d[i][0]+1] = 0
"""
