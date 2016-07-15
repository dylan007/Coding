/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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

int main()
{
	int n,e;
	cin >> n >> e;
	int deg[n];
	int adj[n][n];
	pair<int,int> edges[e];
	memset(deg,0,4*n);
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin >> x >> y;
		x--;
		y--;
		deg[x]++;
		deg[y]++;
		adj[x][y] = adj[y][x] = 1;
		edges[i].first = x;
		edges[i].second = y;
	}
	int check=-1;
	int min=INT_MAX;
	for(int i=0;i<e;i++)
	{
		x = edges[i].first;
		y = edges[i].second;
		for(int k=0;k<n && k!=x && k!=y;k++)
		{
			if(adj[x][k]==adj[y][k] && adj[x][k]==1)
			{
				check=0;
				int sum;
				sum = deg[x]+deg[y]+deg[k]-6;
				min = min<sum?min:sum;
			}
		}
	}
	if(check == 0)
		cout << min << endl;
	else
		cout << "-1" << endl;
	return 0;
}
