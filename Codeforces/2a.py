t = input()
d = {}
names = {}
m = 0

for i in range(t):
	s = raw_input().split()
	d[i] = s
	if s[0] in names.keys():
		names[s[0]][0] += int(s[1])
		names[s[0]][1] = i
		m = max(m,names[s[0]][0])
	else:
		names[s[0]] = [int(s[1]),i]
		m = max(m,names[s[0]][0])

time = 10000000
winner = ""
for i in names.items():
	 if m == i[1][0]:
	 	if time> i[1][1]:
			winner = i[0]
			time  = i[1][1]

print winner
