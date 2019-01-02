import re
t = int(input())
while t>0:
	t = t-1
	s = input()
	f1 = s.find('R')
	f2 = s.find('C')
	m = re.search('\d',s)
	if(f1!=-1 and f2!=-1 and (f2>(f1+1)) and (m.start()<f2)):
		p = s.find('C')
		r = int(s[1:p])
		c = int(s[p+1:])
		C = ""
		while c>0:
			if (c%26) == 0:
				c -= 26
				C = 'Z' + C
			else:
				C = chr(int(c%26) + int(ord('A')) - 1) + C
			c = int(c//26)
		print(C+str(r))
	else:
		r = s[m.start():]
		c = s[:m.start()]
		C = 0
		curr = 1
		for x in c[::-1]:
			C += (ord(x)-ord('A')+1)*curr
			curr *= 26
		print("R"+r+"C"+str(C))