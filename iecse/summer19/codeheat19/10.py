import itertools
from itertools import combinations,chain

def sub_lists(my_list):
    subs = []
    for i in range(1,len(my_list)+1):
        x = [list(p) for p in combinations(my_list,i)]
        subs.extend(x)
    return subs

out = ""
for x in range(1,20):
	# x = int(input())
	l = list(range(x+1))
	p = sub_lists(l)
	c = 0
	mod = 1000000007
	for tmp in p:
		temp = list(tmp)
		f = 1
		for i in range(len(temp)):
			for j in range(i,len(temp)):
				if((temp[i]^temp[j]) not in temp):
					f=0
					break
			if f==0:
				break
		# if(f==1):
		# 	print(temp)
		c = (c+f)%mod
	print(x,c)
print(out)