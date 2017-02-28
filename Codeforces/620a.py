a,b = map(int,raw_input().split())
x,y = map(int,raw_input().split())

a = abs(a-x)
b = abs(b-y)
print max(a,b)
