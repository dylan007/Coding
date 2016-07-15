/*
 * =====================================================================================
 *
 *       Filename:  520b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 May 2015 11:31:35  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>

using namespace std;

int ans=INT_MAX;
int adj[2*1000][2*1000];
int visited[2*1000];

void dfs(int start,int finish,int depth,int m)
{
	cout << start << " " << depth << endl;
	visited[start]=1;
	if(start==finish)
	{
		ans=(ans<depth)?ans:depth;
		return;
	}
	for(int i=1;i<=2*m;i++)
	{
		//cout << adj[start][i] << " " << endl;
		if(adj[start][i]==1)
		{
			if(visited[i]!=1)
				dfs(i,finish,depth+1,m); 
		}
	}
	return;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int size;
	size = (n>m)?n:m;
	for(int i=1;i<=2*size;i++)
		memset(adj[i],0,sizeof(adj[i]));
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=2*size;i++)
	{
		if(i!=1)
			adj[i][i-1]=1;
		adj[i][2*i]=1;
	}	
	/*for(int i=1;i<=2*size;i++)
	{
		for(int j=1;j<=2*size;j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}*/
	dfs(n,m,0,size);
	cout << ans << endl;
	return 0;
}
