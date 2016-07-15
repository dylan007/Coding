l = input()
s1 = map(int,raw_input().split())
s2 = map(int,raw_input().split())
s3 = map(int,raw_input().split())

for i in range(len(s1)):
	if s1[i] not in s2:
		print s1[i]
		break

for i in range(len(s2)):
	if s2[i] not in s3:
		print s2[i]
		break
