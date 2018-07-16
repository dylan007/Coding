dp = [[0 for i in range(5001)] for j in range(5001)]
for i in range(1,5001):
	for j in range(1,i+1):
		if i==j or j==0:
			dp[i][j] = 1
		else:
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

print("done")