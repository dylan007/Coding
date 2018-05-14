n1= input()
l1 = []
l1 = map(int,raw_input().split(' '))
n2 = input()
l2 = map(int,raw_input().split(' '))
for i in range(n1):
	l2.remove(l1[i])
l2 = sorted(l2)
for i in range(len(l2)-1):
	print l2[i],
print l2[len(l2)-1]
