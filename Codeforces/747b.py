import sys

t = input()
s = raw_input()
if t%4 != 0:
	print "==="
	sys.exit(0)


d = ['A','T','G','C'] 
c = {}

for i in range(4):
	c[d[i]] = t/4
	if s.count(d[i]) > t/4 : 
		print "==="
		sys.exit(0)

for i in range(t):
	if s[i] != '?':
		c[s[i]] -= 1

out = "" 
for i in range(t):
	if s[i] == '?':
		while c[d[0]] <= 0:
			d = d[1:]
		out += d[0]
		c[d[0]] -= 1
	else:
		out += s[i]
print out
