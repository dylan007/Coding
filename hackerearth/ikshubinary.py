from operator import mul    # or mul=lambda x,y:x*y
from fractions import Fraction

def nCk(n,k): 
	  return long( reduce(mul, (Fraction(n-i, i+1) for i in range(k)), 1) )

n,k = raw_input().split(' ')
n = long(n)
k = long(k)

ans = 2**n
s = 2**n

for i in xrange(k):
	s -= nCk(n,i)

print str(s)+"/"+str(ans)
