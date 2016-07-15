string = raw_input()
l = len(string)
m = input()
M = map(int,raw_input().split())
ans = string
for i in range(m):
	a = M[i]
	temp = ans[a-1:l-a+1]
	temp = temp[::-1]
	ans = ans[:a-1]+temp+ans[l-a+1:]
print ans
