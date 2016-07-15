/*
 * =====================================================================================
 *
 *       Filename:  609a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 23 December 2015 11:01:58  IST
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
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int c=0;
	for(int i=n-1;i>=0;i--)
	{
		c += (m>0);
		if(m<=0)
			break;	
		m -= a[i];
	}
	cout << c << endl;
	return 0;
}
