l = ["TTT","TTH", "THT", "THH", "HTT", "HTH", "HHT" ,"HHH"]
t = input()
while t>0:
    t = t-1
    x = input()
    c = [0]*len(l)
    s = raw_input()
    for i in range(len(s)-2):
        temp = s[i:i+3]
        c[l.index(temp)] += 1
    print x," ".join(map(str,c))

