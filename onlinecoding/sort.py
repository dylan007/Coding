import sys

s = sys.argv[1]
with open(s,"r") as f:
	content = f.readlines()

content = [x.strip() for x in content]

print 25
# 1 26
# 26 51
# 51 76
# 76 101
for i in range(76,101):
	print content[i]