/*
 * =====================================================================================
 *
 *       Filename:  598a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 28 July 2016 11:36:05  IST
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
	while(n--)
	{
		ll x;
		cin >> x;
		ll p = log(x)/log(2);
		ll ans=(x*(x+1))/2;
		for(ll i=0;i<=p;i++)
			ans = ans - 2*pow(2,i);
		cout << ans << endl;
	}
	return 0;
}
