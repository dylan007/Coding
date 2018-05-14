def isPalin(start):
	temp = repr(start)
	if(temp == temp[::-1]):
		return 1
	else:
		return 0

t = input()
while t>0:
	t = t-1
	start = input()
	start = start+1
	while isPalin(start)==0:
		start = start+1
	print start
