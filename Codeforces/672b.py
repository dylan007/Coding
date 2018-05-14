l = input()
s = raw_input()
x =  l - len(list(set(s)))
if x > 26-len(list(set(s))):
	print "-1"
else:
	print x
