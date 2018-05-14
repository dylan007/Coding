t = int(raw_input())
users = {}
while(t>0):
	string = raw_input()
	if(string not in users):
		print "OK"
		users[string] = 1
	else:
		print string+repr(users[string])
		string1 = string+repr(users[string])
		if(string1 not in users):
			users[string1] = 1
		users[string] = users[string]+1
	t = t-1
