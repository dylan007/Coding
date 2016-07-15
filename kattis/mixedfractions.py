x,y = map(int,raw_input().split(' '))
while x!=0 and y!=0:
	print repr(int(x/y)) + " " + repr(int(x%y)) + " / " + repr(y)
	x,y = map(int,raw_input().split(' '))
