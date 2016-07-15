t = input()
inp = raw_input()
f=0
for i in range(26):
	if chr(i+48) not in inp and chr(i+65) not in inp:
		print chr(i+48) , chr(i+64)
		f=1
		break
if(f==0):
	print "YES"

