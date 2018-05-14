#include<bits/stdc++.h>

using namespace std;

int adj[100][100];
int visited[100];
int n,e;

void dfs(int start)
{
	visited[start] = 1;
	for(int i=0;i<n;i++)
	{
		if(adj[start][i] == 1)
		{
			if(visited[i]!=1)
				dfs(i);
		}
	}
}

int main()
{
	cin >> n >> e;
	for(int i=0;i<n;i++)
		memset(adj[i],0,4*n);
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin >> x >> y;
		adj[x-1][y-1] = 1;
		adj[y-1][x-1] = 1;
	}
	cin >> x >> y;
	dfs(x-1);
	if(visited[y-1] == 1)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
