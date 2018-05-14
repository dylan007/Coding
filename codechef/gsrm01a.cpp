/*
 * =====================================================================================
 *
 *       Filename:  gsrm01a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 06 August 2016 07:31:09  IST
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
	ll T;
	cin >> T;
	while(T--)
	{
		ll n,k,sum=0,x,m=INT_MIN;
		cin >> n >> k;
		for(ll i=0;i<n;i++)
		{
			cin >> x;
			m = max(x,m);
			sum += x;
		}
		if(m>=k || sum>=k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
