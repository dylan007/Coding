l = int(input())
s = input()
for i in range(1,l+1):
	if (l%i)==0:
		temp = s[:i]
		s = temp[::-1] + s[i:]
print(s)