/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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
	int n;
	cin >> n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		ll x;
		x = a[i];
		while(x%2 == 0)
			x /= 2;
		while(x%3 == 0)
			x /= 3;
		a[i] = x;
	}
	int check=1;
	for(int i=1;i<n;i++)
		check &= (a[i]==a[0]);
	if(check == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}
