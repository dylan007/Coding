/*
 * =====================================================================================
 *
 *       Filename:  581b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 28 July 2016 07:55:19  IST
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
	ll ans[n];
	ll M = INT_MIN;
	for(ll i=(n-1);i>=0;i--)
	{
		ans[i] = M-a[i]+1;
		ans[i] = ans[i]<0?0:ans[i];
		M = max(M,a[i]);
	}
	for(ll i=0;i<n;i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
