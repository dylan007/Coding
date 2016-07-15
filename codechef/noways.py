def fact(n):
	if n==1 or n==0:
		return 1
	else:
		return n*fact(n-1)

mod = 1000000007
t = input()
while t>0:
	t = t-1
	n,r = map(int,raw_input().split())
	if(n>=r):
		print (fact(n)/(fact(n-r)*fact(r)))%mod
	else:
	 	print "0" 
