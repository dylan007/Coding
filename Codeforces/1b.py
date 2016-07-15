def convert1(s):
	ind = s.index('C')
	row = int(s[1:ind])
	col = int(s[ind+1:])
	s = ""
	col = col-1
	i=0
	while(col>=0):
		x = col%26
		s = chr(x+ord('A'))+s
		col = col-((x+1) * 26**i)
		i = i+1
	return s+str(col)


t = input()
while t>0:
	s = raw_input()
	if(s[1].isdigit()):
		print convert1(s)
	else:
		print convert2(s)
	t = t-1
