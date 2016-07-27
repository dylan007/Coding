/*
 * =====================================================================================
 *
 *       Filename:  686a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 July 2016 03:21:40  IST
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
	ll n,x;
	cin >> n >> x;
	string a;
	ll y,score=0;
	for(ll i=0;i<n;i++)
	{
		cin >> a;
		cin >> y;
		if(a[0]=='+')
			x += y;
		else
		{
			if(x<y)
				score++;
			else
				x -= y;
		}
	}
	cout << x << " " << score << endl;
	return 0;
}
