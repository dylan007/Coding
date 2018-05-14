
b = {}

def create(T):
	while T>0:
		a1,a2 = raw_input().split()
		b[a1] = a2
		T = T-1

def query(T):
	while T>0:
		a = raw_input()
		out = 'unknown'
		if a.find('.')!=-1:
			a = a.split('.')
			if a[-1] in b:
				print b[a[-1]]
			else:
		 		print out
		else:
			print out
       		T = T-1

x,y = raw_input().split()
x = int(x)
y = int(y)
create(x)

query(y)	
