t = input()
s = raw_input()
b = ""
for i in range(t):
	if s[i] == "B":
		b += "1"
	else:
		b += "0"

lens = []
curr = 0
for i in range(t):
	if b[i]=='0' and curr!=0:
		lens.append(curr)
		curr = 0
	elif b[i]=='1':
		curr += 1
if curr>0:
	lens.append(curr)

print len(lens)
for i in range(len(lens)):
	print lens[i]
