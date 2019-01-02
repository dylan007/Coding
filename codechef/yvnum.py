def shift(x,pow):
	return (x//(pow//10)) + (x%(pow//10))*10


t = int(input())
while t>0:
	t = t-1
	x = input()
	l = len(x)
	x = int(x)
	p = 0
	tmp = l
	while l>0:
		l = l-1
		p = (10**tmp)*p + x
		x = shift(x,10**tmp)
	print(p%1000000007) 