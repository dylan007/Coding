x,y,z = map(int,raw_input().split())
x += y
ans = 0
while x>=z:
	ans += x/z
	x = x/z + x%z
print ans
