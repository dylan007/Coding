/*
 * =====================================================================================
 *
 *       Filename:  165b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 15 July 2016 04:43:56  IST
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

ll lines(ll x,ll k)
{
	int score = x;
	while(x)
	{
		x /= k;
		score += x;
	}
	return score;
}

int main()
{
	ll n,k;
	cin >> n >> k;
	ll l,r;
	ll mid;
	l = 1;
	r = n;
	ll ind;
	while(l <= r)
	{
		mid = (l+r)/2;
		if(lines(mid,k)<n)
			l = mid+1;
		else
		{
			ind = mid;
			r = mid-1;
		}
	}
	cout << ind << endl;
	return 0;
}
