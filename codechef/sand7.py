t = int(input())
arr = [1,2,3,4,5,6,7,6,5,4,3,2,1,1337]
while t>0:
	t = t-1
	n = int(input())
	print(arr[(n-1)%14])