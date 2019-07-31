def modexp(a,b,mod):
	ans=1
	while(b>0):
		if((b%2)==1):
			ans = (ans * a)%mod
		a = (a*a)%mod
		b = b>>1
	return ans


def modinv(a,mod):
	return modexp(a,mod-2,mod)


n,k = map(int,input().split())
arr = list(map(int,input().split()))
for i in range(n):
	arr[i] = arr[i]%k

c = dict()
for i in range(k):
	c[i]=0
for i in range(n):
	c[arr[i]] += 1

ans=0
for i in range(1,k):
	inv = modinv(i,k)
	if(inv!=i):
		if(inv<k):
			ans += max(c[inv],c[i])
		else:
			ans += c[i]

ans = ans>>1

ans += c[0]
print(ans)