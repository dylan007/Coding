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
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int ans=0;
	if(n==1)
	{
		cout << "0" << endl;
		return 0;
	}
	for(int i=0;i<(n-1);i++)
	{
		if(a[i]>=a[i+1])
		{
			ans += a[i]-a[i+1]+1;
			a[i+1] = a[i]+1;
		}
	}
	if(a[n-1]<=a[n-2])
		ans += a[n-2]-a[n-1]+1;
	//for(int i=0;i<n;i++)
	//	cout << a[i] << " ";
	cout << ans << endl;
	return 0;
}
