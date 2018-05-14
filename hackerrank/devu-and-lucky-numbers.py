import itertools

c = map(int,raw_input().split(' '))
mod = 1000000007
s = sum(c)
ans = 15
nums = []
for i in range(c[0]):
	nums.append('4')
for i in range(c[1]):
	nums.append('5')
for i in range(c[2]):
	nums.append('6')
for i in range(2,s+1):
	lst = itertools.permutations(nums,i)
	lst = list(set(lst))
	for j in lst:
		j = list(j)
		temp = ''.join(j)
		l = long(temp)
		ans = (ans%mod + l%mod)%mod
print ans
