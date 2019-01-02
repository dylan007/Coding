t = int(input())
lim = 10**18
while t>0:
	t = t-1
	x,y = map(int,input().split())
	ans = -1
	l = x
	r = x+1
	while l<=lim:
		if l>=y:
			f1 = (l//y) 
			if (l%y)!=0:
				f1 += 1
			f2 = r//y
			if (r%y)==0:
				f2 -= 1
			if f2 >= f1:
				if (f1*y)>lim:
					ans = -1
				else:
					ans = f1*y 
				break
		l *= 10
		r *= 10
	print(ans)