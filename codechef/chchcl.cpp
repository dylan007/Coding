/*
 * =====================================================================================
 *
 *       Filename:  chchcl.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 05 August 2016 06:03:17  IST
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
	ll T;
	cin >> T;
	while(T--)
	{
		ll c,a,b,x,y;
		cin >> a >> b;
		x = (a & -a);
		y = (b & -b);
		c = (log(x)/log(2))+(log(y)/log(2));
		cout<< c << endl;
		if(c%2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
