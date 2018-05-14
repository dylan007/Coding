import math

t = int(input())
for _ in range(t):
	n,s = map(int,raw_input().split())
	if (n==1 and s!=0):
		print(-1)
	elif (n==1):
		print(0)
	else:	
		arr = [0.0] * n
		val = s**2 * n
		arr[0]= round(math.sqrt(val/2),6)
		arr[1] = -arr[0]
		if (str(arr[1]) == "-0.0"):
			arr[1]=0.0
		print(" ".join(map(str,arr)))