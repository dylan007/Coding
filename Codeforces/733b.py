t = input()

legs = []

l = 0
r = 0
for i in range(t):
	s = map(int,raw_input().split())
	legs.append(s)
	l += s[0]	
	r += s[1]

ans = abs(l-r)
ind = -1


for i in range(t):
	x = l-legs[i][0]+legs[i][1]
	y = r-legs[i][1]+legs[i][0]
	if abs(x-y)>ans:
		ans = abs(x-y)
		ind = i

print ind+1
