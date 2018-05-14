/*
 * =====================================================================================
 *
 *       Filename:  586a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 28 July 2016 08:11:30  IST
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

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];
	ll count=0;
	for(ll i=0;i<n;i++)
	{
		count += (a[i]==1);
		count += (i>=1 && i<=(n-2) && a[i]==0 && a[i-1] && a[i+1]);
	}
	cout << count << endl;
	return 0;
}
