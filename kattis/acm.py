s = raw_input()
log = []
ans = 0
solved = []
while s[0] != '-':
	log.append(s)
	x = s.split()
	if x[2]=='right':
		solved.append(x[1])
		ans += int(x[0])
	s = raw_input()
for i in range(len(log)):
	x = log[i].split()
	if x[1] in solved:
		if x[2]=='wrong':
			ans += 20
print len(solved),ans
