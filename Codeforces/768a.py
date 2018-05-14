t = input()
s = map(int,raw_input().split())

l = min(s)
r = max(s)

t -= s.count(l)+s.count(r)
print max(0,t)
