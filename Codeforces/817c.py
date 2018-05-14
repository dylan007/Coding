n,s = map(long,raw_input().split())
x = (s/9)
if s%9 != 0:
    x+=1
if x==0:
    x = x*10+1
else:
    x = x*10
print max(0,n-x+1)

