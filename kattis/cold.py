t = input()
x = map(int,raw_input().split())
print len(filter(lambda p: p<0 ,x))
