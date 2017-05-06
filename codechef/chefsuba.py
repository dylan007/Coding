n,k,p = map(int,raw_input().split())
s = map(int,raw_input().split())
q = raw_input()
x = []
for i in range(n):
    if s[i]==1:
        if len(x)==0:
            x.append(1)
        else:
            if x[-1]>0:
                x[-1] += 1
            else:
                x.append(1)
    else:
        x.append(0)
for i in range(len(q)):
    if q[i]=="!":
        if x[-1]==0:
            temp = x[-1:]+x[:-1]
            x = temp[:]
        else:
            if x[0]==0:
                temp = [1]
                temp += x
                temp[-1] -= 1
                if temp[-1]>0:
                    x = temp[:]
                else:
                    x = temp[:-1]
            else:
                x[0]+=1
                x[-1]-=1
                if x[-1]==0:
                    x = x[:-1]
    else:
        print min(k,max(x))
