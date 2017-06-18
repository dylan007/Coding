s = raw_input()
temp = s[-4:]
out = temp[:-4]
for i in range(4):
    x = len(temp)-i-1
    if x<0:
        break
    t = temp[:x]+temp[x+1:]
    if int(t)%8 == 0:
        temp = t
        break
if int(temp)%8 == 0:
    print "YES"
    print out+temp
else:
    print "NO"
