n = input()
s = map(int,raw_input().strip().split())
while max(s) >= sum(s)/2 :
    x = max(s)
    s.remove(x)
    s.append(x/2)
    s.append(x-x/2)

print len(s)-n