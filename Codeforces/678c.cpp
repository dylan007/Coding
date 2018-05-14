/*
 * =====================================================================================
 *
 *       Filename:  678c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 13 July 2016 10:51:00  IST
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

ll gcd(ll a, ll b)
{
	return !b?a:gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a,b);
}

int main()
{
	ll n,a,b,p,q;
	cin >> n >> a >> b >> p >> q;
	
	ll score=0;
	if(p>q)
	{
		score += (n/a)*p;
		score += (n/b - (n/(lcm(a,b))))*q;
	}
	else
	{
		score += (n/b)*q;
		score += (n/a - (n/(lcm(a,b))))*p;
	}
	
	cout << score << endl;	
	return 0;
}
