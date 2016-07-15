/*
 * =====================================================================================
 *
 *       Filename:  willitst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 June 2016 09:17:37  IST
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
	double pow;
	pow = log2(x);
	if(int(pow)==pow)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
	return 0;
}
