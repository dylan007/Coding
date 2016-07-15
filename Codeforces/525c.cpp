/*
 * =====================================================================================
 *
 *       Filename:  525c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 10 May 2015 09:18:09  IST
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
	long long int n,i;
	cin >> n;
	long long int a[n];
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	long long int len=0,bre=0;
	for(i=(n-2);i>=0;i--)
	{
		if(a[i]==a[i+1] || (a[i]==a[i+1]-1))
		{
			len=a[i];
			break;
		}
	}
	i-=2;
	//cout << i << endl;
	for(;i>=0;i--)
	{
		if(a[i]==a[i+1] || (a[i]==a[i+1]-1))
		{
			bre = a[i];
			break;
		}
	}
	//cout << len << bre << endl;
	cout << len*bre << endl;
	return 0;
}
