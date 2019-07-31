def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)


T = int(input())
for t in range(T):
	out = "Case #" + str(t+1) + ": "
	n,l = map(int,input().split())
	arr = list(map(int,input().split()))
	primes = []
	x = int(arr[0]/gcd(arr[0],arr[1]))
	primes.append(x)
	for i in range(1,l+1):
		primes.append(arr[i-1]/primes[i-1])
	sp = list(set(primes[:]))
	sp = sorted(sp)
	d = {}
	for i in range(len(sp)):
		d[sp[i]] = i
	for i in range(26):
		print(chr(ord('A') + i),sp[i])
	for p in primes:
		out += chr(ord('A') + d[p])
	print(out)
