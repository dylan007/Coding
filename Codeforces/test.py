a = raw_input()
a = a.lstrip().rstrip()
s = '%e' % float(a)
l = s.find('e')
print s[:l].rstrip('0')+'E'+s[l+2:].lstrip('0')
