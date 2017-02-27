s = raw_input()
pos1 = s[0]
pos2 = s[1]

if (s=="a8") or (s=="h8") or (s=="a1") or (s=="h1") :
	print "3"
elif s[0]=="a" or s[0]=="h" or s[1]=="1" or s[1]=="8":
	print "5"
else:
	print "8"
