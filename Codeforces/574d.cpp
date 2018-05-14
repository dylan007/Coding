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
	int a[n+2];
	a[0] = 0;
	a[n+1] = 0;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		a[i] = min(a[i],min(a[i-1]+1,a[i+1]+1));
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		a[i] = min(a[i],min(a[i-1]+1,a[i+1]+1));
		ans = max(ans,a[i]);
	}
	cout << ans << endl;
	return 0;
}
