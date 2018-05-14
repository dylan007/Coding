t = int(input())
while t>0:
    t = t-1
    x = int(input())
    out = ""
    while x>0:
        if x%26 == 0:
            out = "Z" + out
            x = x//27
            continue
        out = chr(ord("A")+int(x%26)-1)+out
        x = x//26
    print(out)
