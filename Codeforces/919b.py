def check(x):
	ans = 0
	while x>0:
		ans += x%10
		x /= 10
	return ans == 10

ans = 0
i = 19
while ans <10000:
	if(check(i)):
		ans += 1
	i += 1
print i