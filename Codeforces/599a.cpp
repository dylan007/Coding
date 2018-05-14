/*
 * =====================================================================================
 *
 *       Filename:  599a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 01:33:02  IST
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
	int d1,d2,d3;
	cin >> d1 >> d2 >> d3;
	cout << min(2*(d1+d3),min(2*(d1+d2),min(d1+d2+d3,2*(d2+d3)))) << endl;
}
