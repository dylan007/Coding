n = input()
l = map(int,raw_input().split())
x = sorted(l,reverse=True)
rank = {}
count = 1
temp = x[0]
rank[temp] = count
for i in range(1,len(x)):
	if temp!=x[i]:
		temp = x[i]
		rank[temp] = count+1
	count = count+1
for i in range(n):
	print rank[l[i]],
