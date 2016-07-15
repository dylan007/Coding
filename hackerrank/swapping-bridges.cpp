/*
 * =====================================================================================
 *
 *       Filename:  swapping-bridges.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 13 September 2015 11:58:05  IST
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

int visited[50000];

void dfs(int start,int v[],int n)
{
	visited[start-1] = 1;
	if(visited[v[start-1]-1]!=1 && start!=v[start-1])
		dfs(v[start-1],v,n);
	return;
}

int check(int x)
{
	for(int i=0;i<x;i++)
	{
		if(visited[i]==0)
			return i+1;
	}
	return -1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		int count=0;
		int v[x];
		
		memset(visited,0,4*x);
		
		for(int i=0;i<x;i++)
			cin >> v[i];
		int t=1;
		while(t >= 0)
		{
			count++;
			dfs(t,v,x);
			t = check(x);
		}
		cout << count-1 << endl;
	}
	return 0;
}
