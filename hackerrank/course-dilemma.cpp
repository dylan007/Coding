/*
 * =====================================================================================
 *
 *       Filename:  course-dilemma.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 13 June 2015 11:33:16  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>
using namespace std;

int M,flag;
int depth[1010];
int adj[1010][1010];

void dfs(int v,int D,int n)
{
	depth[v] = D;
	M = M<D?D:M;
	for(int i=0;i<n;i++)
	{
		if(adj[v][i]==1)
		{
			if(depth[i]!=0)
				flag=1;
			else
				dfs(i,D+1,n);
		}
	}
	return;
}

int main() {
	int T;
	cin >> T;
	while(T--)
	{
		M=1;
		flag=0;
		memset(depth,0,sizeof(depth));
		int n,r;
		cin >> n >> r;
		int x,y;
		for(int i=0;i<r;i++)
			memset(adj[i],0,sizeof(adj[i]));
		for(int i=0;i<r;i++)
		{
			cin >> x >> y;
			adj[x][y]=1;
		}
		depth[x] = 1;
		dfs(1,1,n);
		if(flag==0)
			cout << M+1 << endl;
		else
			cout << "Never Ends!" << endl;
	}
	return 0;
}
