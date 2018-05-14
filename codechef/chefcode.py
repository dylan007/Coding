from operator import mul


def powerset(lst):
    return reduce(lambda result, x: result + [subset + [x] for subset in result],lst, [[]])

n,k = map(int,raw_input().split())
x = map(int,raw_input().split())

count = 0
s = powerset(x)
for i in s:
    x = i[:]
    if len(x)>0:
        ans = reduce(mul,x,1)
        if ans<=k:  
            count += 1
print count
