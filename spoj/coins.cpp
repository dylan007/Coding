/*
 * =====================================================================================
 *
 *       Filename:  coins.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 20 June 2015 07:29:29  IST
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

std::map<ll,ll> con;

ll conv(ll x)
{
	if(con.find(x)!=con.end())
		return con[x];
	else
	{
		ll t;
		t = conv(x/2)+conv(x/3)+conv(x/4);
		t = t>x?t:x;
		con[x] = t;
		return con[x];
	}
}

int main()
{
	ll x;
	con[0]=0;
	con[1]=1;
	con[2]=2;
	while(cin >> x)
		cout << conv(x) << endl;
	return 0;
}
