/*
 * =====================================================================================
 *
 *       Filename:  595a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 12 July 2016 11:22:15  IST
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
	int score=0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		for(int j=0;j<m;j++)
		{
			cin >> x >> y;
			score += x||y;
		}
	}
	cout << score << endl;
	return 0;
}
