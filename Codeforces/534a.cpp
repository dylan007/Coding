/*
 * =====================================================================================
 *
 *       Filename:  534a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 July 2016 04:10:28  IST
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
	if(n==1)
	{
		cout << n << endl;
		cout << n << endl;
		return 0;
	}
	if(n == 2)
	{
		cout << n-1 << endl;
		cout << n-1 << endl;
		return 0;
	}
	if(n==3)
	{
		cout << n-1 << endl;
		cout << n-2 << " " << n << endl;
		return 0;
	}
	if(n==4)
	{
		cout << "4" << endl;
		cout << "3 1 4 2" << endl;
		return 0;
	}
	cout << n << endl;
	for(ll i=1;i<=n;i++)
	{
		if(i%2 != 0)
			cout << i <<" " ;
	}
	for(ll i=1;i<=n;i++)
	{
		if(i%2 == 0)
			cout << i << " " ;
	}
	cout << endl;
}
