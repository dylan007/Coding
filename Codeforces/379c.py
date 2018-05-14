n = int(raw_input())
pres = []
inp = raw_input().split(' ')
for i in range(n):
	pres.append(int(inp[i]))

for i in range(n):
	temp = pres[:i]
	while(pres[i] in temp):
		pres[i] = pres[i]+1
	print pres[i],
print 
