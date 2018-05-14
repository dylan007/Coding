/*
 * =====================================================================================
 *
 *       Filename:  519c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 12 July 2016 11:38:39  IST
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
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int cur = i;
		int leftn = n - i;
		int leftm = m - 2 * i;
		if (leftm >= 0) 
		{
			cur += min(leftm, leftn / 2);
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
	return 0;
}
