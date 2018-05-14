#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,e;
	cin >> n >> e;
	int adj[n][n];
	for(int i=0;i<n;i++)
		memset(adj[i],0,4*n);
	int x,y;
	int visited[n];
	memset(visited,0,4*n);
	for(int i=0;i<e;i++)
	{
		cin >> x >> y;
		adj[x-1][y-1] = 1;
		adj[y-1][x-1] = 1;
	}
	cin >> x >> y;
	visited[x-1] = 1;
	int stack[3*n];
	int head=0;
	stack[head++] = x;
	int v;
	while(head>=0)
	{
		v = stack[head--];
		if(visited[v-1]==0)
		{
			visited[v-1]=1;
			for(int i=0;i<n;i++)
			{
				if(adj[v-1][i]==1)
					stack[head++] = v;
			}
		}
	}
	if(visited[y-1]==1)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
