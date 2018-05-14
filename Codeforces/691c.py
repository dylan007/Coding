a = raw_input()
if(len(a)==1):
	print a
elif(a.find('.')==-1):
	l = len(a)
	a = a.lstrip('0').rstrip('0')
#print a
	if(len(a)>1):
		print a[:1]+"."+a[1:]+"E"+str(l-1)
	else:
		print a+"E"+str(l-1)

else:
	a = a.lstrip('0').rstrip('0')
#print a
	pos = a.index('.')
	if pos==0:
		s = a.replace('.','')
		l = len(s)
		s = s.strip('0')
		if(len(s)==1):
			print s+"E"+str(1-l-1)
		else:
			print s[:1]+"."+s[1:]+"E"+str(len(s)-l-1)
	elif pos==1:
		if(len(a)>2):
			print a
		else:
		 	print a.replace('.','')
	else:
		s = a.replace('.','')
		s = s.lstrip('0').rstrip('0')
		if len(s)==1:
			print s.replace('.','')+"E"+str(pos-1)
		else:
			s = s[:1]+"."+s[1:]
			print s+"E"+str(pos-1)
