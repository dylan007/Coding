/*
 * =====================================================================================
 *
 *       Filename:  629a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 10 July 2016 08:48:01  IST
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
		string s;
		cin >> s;
		for(int j=0;j<n;j++)
		{
			if(s[j] == 'C')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
			count += a[i][j];
		ans += (count*(count-1))/2;
	}
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
			count += a[j][i];
		ans += (count*(count-1))/2;
	}
	cout << ans << endl;
	return 0;
}
