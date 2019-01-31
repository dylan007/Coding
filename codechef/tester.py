import sys

def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

t = int(input())
score = 0
while t>0:
	t = t-1
	n = input()
	print("\n\n")
	print("N: " + str(n))
	print("Verdict: ")
	f=False
	s = list(map(int,raw_input().split()))
	if(s[0]==-1):
		score += 1
		print("Successful")
		continue
	for i in s:
		if i<1 or i>10**9:
			print("out of range")
			print(i)
			f = True
			break
	if f:
		continue
	l = list(set(s))
	if len(s) != len(l):
		print("Not distinct")
		print(len(l),len(s))
		f = True
		continue


	for i in range(len(s)):
		if gcd(s[i],s[(i+1)%len(s)])==1:
			print("Adjacent Coprime")
			print(i)
			f = True
			break
	if f:
		continue
	for i in range(len(s)):
		if gcd(gcd(s[i],s[(i+1)%len(s)]),s[(i+2)%len(s)])!=1:
			print(' '.join(map(str,s)))
			print("Cyclically not coprime")
			print(i)
			f = True
	if not f:
		print("Successful")
		score += 1

print(score)
