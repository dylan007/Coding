/*
 * =====================================================================================
 *
 *       Filename:  610a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 31 July 2016 10:43:38  IST
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
	ll x;
	cin >> x;
	if(x<4 || x%2 != 0)
		cout << "0" << endl;
	else
	{
		x /= 2;

		cout << x/2 - !(x%2) << endl;
	}
	return 0;
}
