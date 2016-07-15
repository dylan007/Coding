import operator

def LCP(a,b):
	l = len(a)
	if(l>len(b)):
		l = len(b)
	if(a[0]!=b[0]):
	 	return 0
	for i in range(l):
		if(a[i]!=b[i]):
			return i+1
	return i+1

T = int(raw_input())
for t in range(T):
	inp = raw_input()
	suffix = {}
	for i in range(len(inp)):
		suffix[i] = inp[i:]
	suf1 = sorted(suffix.items(),key=operator.itemgetter(1))
	ans = len(suf1[0][1])
	for i in range(1,len(suf1)):
		ans += len(suf1[i][1]) - LCP(suf1[i-1][1],suf1[i][1])
	print ans
