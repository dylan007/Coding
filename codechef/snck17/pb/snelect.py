t = input()
while t>0:
    t = t-1
    s = raw_input()
    i=0
    count=0
    while i<len(s):
        if s[i]=='s':
            if i!=0 and i!=(len(s)-1):
                if s[i-1]=='m':
                    s = s[:i-1]+s[i+1:]
                    count += 1
                elif s[i+1]=='m':
                    s = s[:i]+s[i+2:]
                    count += 1
            elif i==0:
                if s[i+1]=='m':
                    s = s[i+2:]
                    count += 1
            else:
                if s[i-1]=='m':
                    s = s[:i-2]
                    count += 1
        i += 1
    m = s.count('m')
    x = s.count('s')
    m += count
    if m>x:
        print "mongooses"
    elif m<x:
        print "snakes"
    else:
        print "tie"
