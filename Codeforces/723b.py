l = input()
s = raw_input()
s = s.replace("()","(_)")
s = s.replace(")(",")_(")
f1 = 0
if s[0]=="(":
	f1 = 1
s = s.replace(')','(')
x = s.split('(')
x = filter(None,x)
out = 0
ins = 0


for i in range(len(x)):
	if i%2 == f1:
		temp = [len(t.replace("_","")) for t in x[i].split("_")]
		out = max(max(temp),out)
	else:
		temp = filter(None,x[i].split("_"))
		ins += len(temp)
print out,ins
