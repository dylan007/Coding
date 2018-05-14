/*
 * =====================================================================================
 *
 *       Filename:  chefst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 06 December 2015 03:22:36  IST
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
	int T;
	cin >> T;
	while(T--)
	{
		int x,y,m;
		cin >> x >> y >> m;
		m = m*(m+1);
		m /=2;
		x = x-m;
		y = y-m;
		cout << x+y << endl;
	}
	return 0;
}
