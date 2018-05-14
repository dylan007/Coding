T = input()
while T>0:
	T = T-1
	n,k,p = map(long,raw_input().split(' '))
	X = []
	X = map(long,raw_input().split(' '))
	count=0
	flag=0
	for i in range(1,n+1):
		print i
		if i not in X:
			count = count+1
		if(count==p):
			print i
			flag=1
			break
	if(flag==0):
		print "-1"
