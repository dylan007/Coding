/*
 * =====================================================================================
 *
 *       Filename:  621a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 02:03:33  IST
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
	ll sum=0;
	for(ll i=0;i< n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a,a+n);
	ll i=0;
	while(sum%2!=0 && i<n && sum>0)
	{
//		cout << a[i] << endl;
//		cout << sum << endl;
		if(a[i]%2 != 0)
			sum -= a[i];
		i++;
	}
	cout << sum << endl;
	return 0;
}
