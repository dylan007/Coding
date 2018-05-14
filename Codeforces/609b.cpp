/*
 * =====================================================================================
 *
 *       Filename:  609b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 23 December 2015 05:19:41  IST
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
	int c[m];
	memset(c,0,4*m);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		c[a[i]-1]++;
	}
	
	return 0;
}
