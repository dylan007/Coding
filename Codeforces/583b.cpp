/*
 * =====================================================================================
 *
 *       Filename:  583b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 28 July 2016 08:37:41  IST
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
	ll score=0;
	ll change=-1;
	while(score<n)
	{
		for(ll i=0;i<n;i++)
		{
			if(score>=a[i] && a[i]!=-1)
			{
				score++;
				a[i]=-1;
			}
		}
		change++;
		if(score==n)
			break;
		for(ll i=(n-1);i>=0;i--)
		{
			if(score>=a[i] && a[i]!=-1)
			{
				score++;
				a[i]=-1;
			}
		}
		change++;
	}
	cout << change << endl;
}
