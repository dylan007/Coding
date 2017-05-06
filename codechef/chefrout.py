t = input()
while t>0:
    t = t-1
    s = raw_input()
    if ''.join(sorted(s)) == s:
        print "yes"
    else:
        print "no"

