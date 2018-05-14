def palin(inp):
	if(inp==inp[::-1]):
		return 1
	else:
		return 0

a = raw_input()
temp = 0
k = input()
t = k
k = len(a)/k
flag=0
while temp<len(a):
	if(palin(a[temp:temp+k])!=1):
		flag=1
	temp = temp+k
if(flag==0 and len(a)%t==0):
	print "YES"
else:
	print "NO"
