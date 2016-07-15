n = int(raw_input())
t = input()
while t>0:
	t = t-1
	command = raw_input()
	if command[0] == '@':
		n = n+1
	else:
		n = n-1
print n
