def calc(n,m):
    degree = [0]*n
    degree[0] = m
    ans = 0
    count = 0
    while(degree[n-1]!=m) :
    	visited = [0]*n
    	count += 1
    	for i in range(1,n):
            if(degree[i] == m):
                continue
	    if visited[i]==0 and degree[i-1]>0 and visited[i-1]==0 :
                degree[i] += 1
		visited[i] = 1
		visited[i-1] = 1
	print " ".join(map(str,degree))
    return count

t = int(raw_input())
for _ in range(t) :
    n,m = map(int,raw_input().split())
    print calc(n,m)
