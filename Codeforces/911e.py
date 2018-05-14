import sys

n,k = map(int,raw_input().split())
prefix = map(int,raw_input().split())

div = [(1,n)]
i = 0
while True:
	l = div[0][0]
	r = div[0][1]
	if i>=k:
		break
	if prefix[i]<l or prefix[i]>r:
		print "-1"
		sys.exit(0)
	div = div[1:]
	if l==r and l==prefix[i]:
		pass
	elif l==prefix[i]:
		div = [(l+1,r)] + div
	elif r==prefix[i]:
		div = [(l,r-1)] + div
	else:
		div = [(l,max(l,prefix[i]-1))] + [(min(r,prefix[i]+1),r)] + div
	#print div
	i += 1

print " ".join(map(str,prefix)),
for i in range(len(div)):
	l,r = div[i]
	for j in range(r,l-1,-1):
		print j,
print ""