def nCr(n,r,mod):
	if(n<r):
		return 0
	num = 1
	denum = 1
	while r>0:
		num *= n
		denum *= r
		n -= 1
		r -= 1
	num = int(num//denum)
	return num%mod

def modexp(a,b,mod):
	ans = 1
	while b>0:
		if (b%2) == 1:
			ans = (ans * a)%mod
		a = (a*a)%mod
		b = b>>1
	return ans

t = int(input())
mod = 1000000007
while t>0:
	t = t-1
	n,k = map(int,input().split())
	arr = map(int,input().split())
	arr = sorted(arr)
	ans = 1
	l = 1
	r = n-2
	k -= 1
	phi = mod-1
	base = nCr(n-1,k,phi)
	p1 = 1
	p2 = nCr(r,k,phi)
	# print(n,k,p1,p2)
	end = int(n/2) + n%2
	for i in range(1,end):
		power = base
		if l==k:
			power = (power%phi - p1%phi + phi)%phi
		if l>k:
			scale = int(int(k*p1)/int(l-k))
			# print("scale1 = ",scale)
			p1 = int(int(p1 * l)/int(l-k))
			power = (power%phi - (r*p1)%phi + phi)%phi
		if r>=k:
			# print("p2 =",p2,"r =",r,"k =",k)
			power = (power%phi - (l*p2)%phi + phi)%phi
			if r>k:
				scale = int(int(k*p2)/int(r-k)) %phi
				# print("scale2 = ",scale)
			p2 = int(int(p2 * (r-k))/int(r)) 
		# print(l,r,k,p1,p2)
		# print(arr[i],power)
		# print(arr[l],arr[r],power)
		if l!=r:
			ans = (ans * modexp((arr[l]*arr[r])%mod,power,mod))%mod
		else:
			ans = (ans * modexp(arr[l],power,mod))%mod
		l += 1
		r -= 1 
	print(ans)