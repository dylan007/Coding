/*
 * =====================================================================================
 *
 *       Filename:  701a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 31 July 2016 02:08:23  IST
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

ll b[110],n;


int main()
{
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a,a+n);
	ll sum=0;
	sum = a[0]+a[n-1];
	for(ll i=0;i<n/2;i++)
	{
		ll p1=-1,p2=-1;
		for(ll j=0;j<n;j++)
		{
			if(a[i]==b[j] && b[j]>0 && p1<0)
			{
				p1 = j+1;
				b[j]=0;
			}
			else if((sum-a[i])==b[j] && b[j]>0 && p2<0)
			{
				p2 = j+1;
				b[j] = 0;
			}
		}
		cout << p1 << " " << p2 << endl;
	}
	return 0;
}
