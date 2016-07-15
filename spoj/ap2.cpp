/*
 * =====================================================================================
 *
 *       Filename:  ap2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 03 June 2016 08:13:23  IST
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

int main()
{
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int a3,A3,s;
		cin >> a3 >> A3 >> s;
		long long int n,a,d;
		n = (2*s)/(a3+A3);
		d = (A3-a3)/(n-5);
		a = a3-2*d;
		//cout << n << " " << a << " " << d << endl;
		cout << n << endl;
		while(n--)
		{
			cout << a << " ";
			a += d;
		}
		cout << endl;
	}
	return 0;
}
