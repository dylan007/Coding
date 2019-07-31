LIM = 10000

def isPrime(x):
    curr=2
    while (curr*curr)<=x:
        if (x%curr)==0:
            return False
        curr += 1
    return True

def pow(a):
    ans = 1
    c = a
    while c>0:
        c -= 1
        ans *= a
    return ans


t = int(input())
l = []
s = set()
l = list(sorted(l))
curr = 2
while curr<=LIM:
    if isPrime(curr):
        l.append(curr)
        s.add(curr)
        if(curr<=5):
            l.append(pow(curr))
            s.add(pow(curr))
    curr+=1

l = list(sorted(l))

while t>0:
    t = t-1
    x = int(input())
    if(x in s):
        print(1)
    elif((x%2)==0):
        print(2)
    else:
        ind = 0
        for i in range(len(l)):
            if(l[i]>x):
                ind = i
                break
        ind-=1
        if(((x-l[ind])==2) or (x-l[ind] == 4)):
            print(2)
        else:
            print(3)
