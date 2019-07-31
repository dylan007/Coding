s = input()
ind = []
for i in range(len(s)):
	if(s[i]=='*'):
		ind.append(i)

ans=0
for i in range(len(ind)):
	for j in range(i+1,len(ind)):
		l = ind[i]
		r = ind[j]
		lval = eval(s[:l])
		rval = eval(s[r+1:])
		mval = eval(s[l+1:r])
		sdash = s[:l+1] + str(mval) + s[r:]
		ans = max(ans,eval(sdash))
		# print(ans,sdash)
print(ans)