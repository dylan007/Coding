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
	int n,m,q;
	cin >> n >> m >> q;
	int a[n][m];
	int i,j;
	int back;
	int max[n],MAX=0;
	memset(max,0,sizeof(max));
	for(i=0;i<n;i++)
	{
		int count=0;
		for(j=0;j<m;j++)
		{
			cin >> a[i][j];
			if(a[i][j]==1)
				count++;
			else
			{
				max[i]=max[i]<count?count:max[i];
				count=0;
			}
		}
		max[i] = max[i]<count?count:max[i];
		if(MAX<max[i])
		{
			back = i;
			MAX = MAX<max[i]?max[i]:MAX;
		}
	}
	int x,y;
	while(q--)
	{
		cin >> x >> y;
		x--;
		y--;
		a[x][y] = !a[x][y];
		int count=0;
		int M=0;
		for(i=0;i<m;i++)
		{
			if(a[x][i]==1)
				count++;
			else
			{
				M = M>count?M:count;
				count=0;
			}
		}
		M = M>count?M:count;
		max[i]=M;
		if(back!=x)
			MAX = MAX<M?M:MAX;
		else
			MAX = M;
		back = x;
		cout << MAX << endl;
	}
	return 0;
}
