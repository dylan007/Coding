/*
 * =====================================================================================
 *
 *       Filename:  prcs16a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 06 August 2016 09:01:58  IST
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
	ll p1,p2,p3,w;
	cin >> p1 >> p2 >> p3 >> w;
	ll x;
	x = max(p1+p2,p2+p3);
	x = max(p1+p3,x);
	if(x>=w)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
