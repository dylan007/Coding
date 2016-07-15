/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 11 October 2015 04:44:30  IST
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
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	for(ll i=1;i<n;i++)
		arr[i] += arr[i-1];
	ll x,y;
	cin >> x;
	while(x--)
	{
		ll k;
		cin >> k;
		y = n/(k+1) + (n%(k+1) != 0);
		cout << arr[y-1] << endl;	
	}
	return 0;
}
