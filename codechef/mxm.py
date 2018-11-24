import math
t = int(input())
while t>0:
	t -= 1
	n,k = map(int,input().split())
	arr = list(map(int,input().split()))
	# print(arr)
	p = []
	tot = 0
	for i in range(n):
		x = 1
		b = arr[i]
		curr = k
		while b>=1:
			if (b%2)==1:
				x = x*curr
			curr = curr*curr
			b = int(b/2)
		p.append(x)
		tot += p[i]
	# print(p)
	curr=p[0]
	ans = curr * (tot-curr)
	index = 1
	for i in range(1,n-1):
		curr += p[i]
		r = tot - curr
		if (curr*r) > ans:
			index = i+1
			ans = curr*r
	print(index)