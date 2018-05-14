t = input()
s = map(int,raw_input().split())

m = 1
curr = 1
for i in range(1,t):
	if s[i]>s[i-1]:
		curr += 1
	else:
		m = max(curr,m)
		curr=1
m = max(m,curr)
print m
