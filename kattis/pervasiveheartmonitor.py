import sys
for line in sys.stdin:
	s = line.split()
	name = ' '.join(filter(lambda x: x.isalpha(), s))
	vals = map(float,filter(lambda x: x.replace('.','',1).isdigit(),s))
	print "{0:.6f}".format(sum(vals)/len(vals)),name
