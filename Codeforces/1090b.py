bb = "\\begin{thebibliography}{99}"
s = input()
order = []
d = {}
while s!=bb:
	if(s == ''):
		s = input()
		continue
	s = (s.split(' '))
	for p in s:
		if(p[0]=='\\'):
			l = p.find('{')
			r = p.find('}')
			# print(p[l+1:r])
			order.append(p[l+1:r])
	s = input()
be = "\\end{thebibliography}"
border = []
s = input()
while s!=be:
	s = (s.split(' '))
	for p in s:
		if(p[0]=='\\'):
			l = p.find('{')
			r = p.find('}')
			# print(p[l+1:r])
			border.append(p[l+1:r])
			d[p[l+1:r]] = ' '.join(s)
	s = input()
f = True
for i in range(len(order)):
	if order[i] != border[i]:
		f = False
if f:
	print("Correct")
else:
	print("Incorrect")
	print(bb)
	for i in range(len(order)):
		print(d[order[i]])
	print(be)