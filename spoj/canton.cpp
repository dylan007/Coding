/*
 * =====================================================================================
 *
 *       Filename:  canton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 03 June 2016 10:22:31  IST
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

ll cantor(ll x)
{
	return int(ceil((pow(8*x+1,0.5)-1)/2));
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll x;
		cin >> x;
		ll diag;
		diag = cantor(x);
		diag--;
		ll p = diag*(diag+1);
		p /= 2;
		diag++;
		if(diag%2 == 0)
			cout << "TERM " << x << " IS " << (1+x-p-1) << "/" << (diag-x+p+1) << endl;
		else
			cout << "TERM " << x << " IS " << (diag-x+p+1) << "/" << (1+x-p-1) << endl;
	}
	return 0;
}
