def fact(num):
	p = 1;
	while num>=2 :
		p = p*num
		num = num-1
	print p

def test(n):
	while n>=1:
		num = input()
		fact(num)
		n = n-1

n = input()
test(n)
