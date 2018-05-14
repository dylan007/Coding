n,k = map(int,raw_input().split())
lens = []
for i in range(n):
	s = raw_input()
	lens.append(len(s))
p = raw_input()
lens = sorted(lens)
l = lens.index(len(p))+1
r = len(lens)-lens[::-1].index(len(p))
x=0
y=0
if l%k==0:
	x = 1
if r%k==0:
	y = 1
print l+(l/k-x)*5 , r+(r/k-y)*5
