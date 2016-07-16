n = input()
s = raw_input()
ans = 0
if n > len(s):
	print '0'
else:
	for i in range(n+(n==0),len(s)+1):
		for j in range(len(s)-i+1):
#print s[j:j+i]
			ans = ans + (s[j:j+i].count('1') == n)
	print ans
