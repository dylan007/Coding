import operator

inp = [map(int,x) for x in raw_input().split(' ')]
INP = [map(int,x) for x in raw_input().split(' ')]

client = {}
t = inp[0]
for i in range(t):
	temp = [map(int,x) for x in raw_input().split(' ')]
	client.key = i
	client.value = temp[0]*INP[0] + temp[1]*INP[1]

s_client = sorted(client.items(),key=operator.itemgetter(1))

ans = []

key=0
while inp[1]>=0:
	inp[1] = inp[1]-client[key]
	if inp[1]>=0:
		ans.append(client[key])
		key = key+1

print key+1
for i in range(key):
	print client[key],
