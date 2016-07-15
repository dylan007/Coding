#include<bits/stdc++.h>

using namespace std;

int adj[2000][2000];
int MAX=0;
int visited[2000];
int n;

void dfs(int node,int depth)
{
	MAX = max(depth,MAX);
	for(int i=0;i<n;i++)
	{
		if(adj[node][i]==1)
		{
			if(visited[i]!=1)
				dfs(i,depth+1);
		}
	}
}

int main()
{
	int x;
	cin >> n;
	vector<int> roots;
	for(int i=0;i<n;i++)
	{
		memset(adj[i],0,4*n);
		memset(visited,0,4*n);
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x== -1)
		{
			roots.push_back(i);
			count++;
		}
		else
			adj[x-1][i]=1;
	}
	for(int i=0;i<count;i++)
		dfs(roots[i],1);
	cout << MAX << endl;
	return 0;
}
