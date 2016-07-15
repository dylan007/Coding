/*
 * =====================================================================================
 *
 *       Filename:  fence1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 03 June 2016 06:25:57  IST
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
	float l,a;
	cin >> l;
	while(l>0)
	{
		a = (l*l)/(2*M_PI);
		cout << fixed << setprecision(2) << a << endl;
		cin >> l;
	}
	return 0;
}
