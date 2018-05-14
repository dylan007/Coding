n = input()
inp1 = raw_input()
inp2 = raw_input()
x1 = int(inp1,2)
x2 = int(inp2,2)
if(n%2 == 0):
	if(x1 == x2):
		print "Deletion succeeded"
	else:
	 	print "Deletion failed"

else:
	f=0
	for i in range(len(inp1)):
		if(inp1[i] == inp2[i]):
			f=1
			break
	if(f==0):
		print "Deletion succeeded"
	else:
	 	print "Deletion failed"
