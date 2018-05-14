import operator
t = input()
dic = {}
while t>0:
	t = t-1
	a = raw_input()
	if a not in dic.keys():
		dic[a] = 1
	else:
		dic[a] = dic[a]+1
print dic
s_dic = sorted(dic.items(),key=operator.itemgetter(0))
for i,j in s_dic.items():
	print i,j
