def check(s):
    temp = s[:2]+s[3:]
    if temp == temp[::-1]:
        return True
    else:
        return False

def change(s):
    a = int(s[:2])
    b = int(s[3:])
    b += 1
    if b==60:
        a += 1
        if a==24:
            a = 0
        b = 0
    if a<10:
        t = "0"
    else:
        t = ""
    if b<10:
        t = t + str(a)+":0"+str(b)
    else:
        t = t + str(a) + ":" + str(b) 
    return t

s = raw_input()
x = 0
while True:
    if check(s):
        print x
        break
    s = change(s)
    x += 1


