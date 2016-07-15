n = input()
M = -2000
win = ""
s={}
while n>0:
	n = n-1
	name,score = raw_input().split()
	score = int(score)
	if name not in s.keys():
		s[name] = score
	else:
		s[name] += score
	if s[name]>M:
		win = name
		M = s[name]
print win
