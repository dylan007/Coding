/*
 * =====================================================================================
 *
 *       Filename:  hso8test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 June 2016 04:58:29  IST
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
	double x,y;
	cin >> x >> y;
	cout << std::fixed;
	if(x>y || int(x)%5!=0)
		cout << std::setprecision(2) <<  y << endl;
	else
		cout << std::setprecision(2) << double(y-x-0.50) << endl;
	return 0;
}
