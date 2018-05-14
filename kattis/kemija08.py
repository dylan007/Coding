inp = raw_input()
vowels = ['a','e','i','o','u']
out=[]
out.append(inp[0])
for i in range(1,len(inp)):
	if(inp[i-1] not in vowels):
		out.append(inp[i])
print ''.join(out)
