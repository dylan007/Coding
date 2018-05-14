def solve(arr,m,n):
	s = [0]*n 
	ans = 0
	x = 0
	for i in range(m):
		s[i] = (x+arr[i])%2
		if i>=n-1:
			x += s[i] - s[i-n+1]
    	ans += s[i]
    	if(i>m-n and s[i]!=1): 
    		return -1
	return ans

t = input()
while t>0:
	t = t-1
	s = raw_input().split(" ")
	x = s[0]
	k = int(s[1])
	arr = []
	for i in range(len(x)):
		if x[i]=='-':
			arr.append(0)
		else:
			arr.append(1)
	print arr
	print solve(arr,len(s),k)