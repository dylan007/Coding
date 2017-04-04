t = input()
b = ".*"
a = "*."

while t>0:
	t = t-1
	x,y = map(int,raw_input().split())
	u = a*(y/2) + a[:y%2]
	v = b*(y/2) + b[:y%2]
	for i in range(x/2):
		print u
		print v
	if x%2 == 1:
		print u

