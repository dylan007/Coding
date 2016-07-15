t = int(raw_input())
while t>0:
	t = t-1
	eq = raw_input()
	if('+' in eq):
		op1,op2 = eq.split('+')
		op1 = long(op1)
		op2 = long(op2)
		print op1+op2
	else:
	 	op1,op2 = eq.split('-')
	 	op1 = long(op1)
	 	op2 = long(op2)
	 	print op1-op2
