/*
 * =====================================================================================
 *
 *       Filename:  findingProffession.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 16 August 2016 10:19:52  IST
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

ll countsetbits(ll x)
{
	ll count=0;
	while(x>0)
	{
		count++;
		x &= (x-1);
	}
	return count;
}

int main()
{
	ll T;
	cin >> T;
	ll x;	
	while(T--)
	{
		ll pos,l;
		cin >> l >> pos;
		pos--;
		ll x = countsetbits(pos);
		if(x%2 == 0)
			cout << "Engineer" << endl;
		else
			cout << "Doctor" << endl;
	}
	return 0;
}
