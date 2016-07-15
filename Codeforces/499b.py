n,m = raw_input().split(' ')
n = int(n)
m = int(m)
lang = {}
for i in range(m):
	x,y = raw_input().split(' ')
	lang[x]=y
string = raw_input().split()
for i in range(n):
	x = string[i]
	y = lang[string[i]]
	if(len(x)<len(y)):
		print x,
	elif(len(x)>len(y)):
		print y,
	else:
	 	print x,
