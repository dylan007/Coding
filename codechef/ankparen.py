from itertools import *
def check(S):
	stack = []
	for i in range(len(S)):
		if(S[i]=="("):
			stack.append(S[i])
		else:
			if stack:
				x = stack.pop()
			else:
				return 0
	if not stack:
		return 1
	else:
	 	return 0

t = input()
while t>0:
	string = raw_input()
	ans = []
	for i in range(1,len(string)+1):
		temp = list(combinations(string,i))
		#print temp
		for j in range(len(temp)):
			s = ""
			for k in range(i):	
				s += temp[j][k]
			if s not in ans:
				ans.append(s)
	
	#print ans
	for i in range(len(ans)-1,-1,-1):
		if(check(ans[i]) == 0):
#		print ans[i]
			break
	l = len(ans[i])
	temp = []
	for i in range(len(ans)-1,-1,-1):
		if(len(ans[i])==l):
			temp.append(ans[i])
	temp.sort()
	k = input()
	if(k > len(temp)):
		print "-1"
	else:
	 	print temp[k-1]
	t = t-1

