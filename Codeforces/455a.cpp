/*
 * =====================================================================================
 *
 *       Filename:  455a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 15 July 2016 04:01:58  IST
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
	vector<int> c(100001,0);
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		c[a[i]]++;
	}
	sort(a,a+n);
	
	return 0;
}
