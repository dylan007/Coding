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
	int n;
	cin >> n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin >> a[i][j];
	}
	int check[n];
	memset(check,0,sizeof(check));
	int count=n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			count -= (check[i]==0 && (a[i][j]==3 || a[i][j]==1));
			count -= (check[j]==0 && (a[i][j]==3 || a[i][j]==2));
			if(a[i][j]==3)
				check[i]=check[j]=1;
			else if(a[i][j]==2)
				check[j]=1;
			else if(a[i][j]==1)
				check[i]=1;
		}
	}
	cout << count << endl;
	for(int i=0;i<n;i++)
	{
		if(check[i]==0)
			cout << i+1 << " ";
	}
	cout << endl;
	return 0;
}
