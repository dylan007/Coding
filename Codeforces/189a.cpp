/*
 * =====================================================================================
 *
 *       Filename:  189a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 25 July 2016 08:18:11  IST
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

ll num[5000],a,b,c,n;

ll score(ll m)
{
	ll x,y,z;
	if(m < 0)
		return -10000;
	if(num[m] == -1)
	{
		x = score(m-a)+1;
		y = score(m-b)+1;
		z = score(m-c)+1;
		if(x>=y && x>=z)
			num[m] = x;
		else if(y>=x && y>=z)
			num[m] = y;
		else if(z>=x && z>=y)
			num[m] = z;
	}
	return num[m];
}


int main()
{
	cin >> n >> a >> b >> c;
	for(ll i=0;i<=4000;i++)
		num[i] = -1;
	num[0]=0;
	cout << score(n) << endl;
	return 0;
}
