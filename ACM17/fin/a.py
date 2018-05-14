t = input()
while t>0:
    t = t-1
    a = map(int,raw_input().split())
    b = map(int,raw_input().split())
    c = map(int,raw_input().split())
    l = []
    l.append(a)
    l.append(b)
    l.append(c)
    l.sort(key = lambda row:(row[0])) 
    m = l[:]
    ans = 0
    for i in range(2):
        if l[i] == l[i+1]:
            ans = 1
    m.sort(key = lambda row:(row[1]))
    for i in range(2):
        if m[i] != l[i] and l[i][0] == m[i][0]:
            ans = 1
    n = m[:]
    n.sort(key = lambda row:(row[2]))
    for i in range(2):
        if n[i] != m[i] and m[i][1] == n[i][1]:
            ans = 1
    print(m)
    if(ans):
        print("no")
    else:
        print("yes")