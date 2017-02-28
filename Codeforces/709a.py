n,b,d = map(int,raw_input().split())
s = map(int,raw_input().split())
curr = 0
ans = 0
for i in range(n):
	if s[i] > b:
		continue
	curr += s[i]
	if curr > d:
		ans +=1
		curr = 0
print ans
