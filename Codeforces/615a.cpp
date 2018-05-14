/*
 * =====================================================================================
 *
 *       Filename:  615a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 06:18:13  IST
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
	int n,m;
	cin >> n >> m;
	int flag[m];
	for(int i=0;i<m;i++)
		flag[i]=0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x;
		for(int j=0;j<x;j++)
		{
			cin >> y;
			flag[y-1] = 1;
		}
	}
	//for(int i=0;i<m;i++)
	//	cout << flag[i] << endl;
	int f=0;
	for(int i=0;i<m;i++)
	{
		if(flag[i]==0)
			f=1;
	}
	if(f==1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
