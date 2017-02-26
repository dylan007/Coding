n,k = map(int,raw_input().split())
s = map(int,raw_input().split())

sums = []
sums.append(s[0])

for i in range(1,n):
	sums.append(sums[i-1]+s[i])

m = sums[k-1]
ind = k-1
for i in range(k,n):
	x = sums[i]-sums[i-k]
	if x<m:
		m = x
		ind = i
print ind-k+2
