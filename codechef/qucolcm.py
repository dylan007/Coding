import operator

t = int(raw_input())
for i in range(t):
	n = int(raw_input())
	times = {}
	for j in range(n):
		x,y = raw_input().split(' ')
		times[int(x)] = int(y)
	time = sorted(times.items(),key=operator.itemgetter(0))
	print time
