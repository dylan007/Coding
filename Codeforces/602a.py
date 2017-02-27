l1, b1 = map(int, raw_input().split())
a = map(int, raw_input().split())

x =0
for i in range(l1):
	x += (b1**(l1-i-1))*(a[i]) 


l2, b2 = map(int, raw_input().split())
b = map(int, raw_input().split())

y =0
for i in range(l2):
    y += (b2**(l2-1-i))*b[i]


if x < y:
	print "<"
elif x > y:
	print ">"
else:
	print "="
