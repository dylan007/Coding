t = int(input())
curr = []
while t>0:
	t = t-1
	s = input()
	if s[0]=='p':
		out = "/"
		for i in range(len(curr)):
			out += curr[i]
			out += "/"
		print(out)
	else:
		s = s.split()[1]
		if s[0]=='/':
			s = s.split('/')[1:]
			curr = []
			for i in range(len(s)):
				if(s[i]=='..'):
					curr = curr[:-1]
				else:
					curr.append(s[i])
		else:
			s = s.split('/')
			for i in range(len(s)):
				if(s[i]==".."):
					curr = curr[:-1]
				else:
					curr.append(s[i])
