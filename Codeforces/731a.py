pos = "abcdefghijklmnopqrstuvwxyz"

s = raw_input()

ans = 0
curr = 0
for i in range(len(s)):
	ans += min(26-abs(curr-pos.find(s[i])),abs(curr-pos.find(s[i])))
	curr = pos.find(s[i])
print ans
