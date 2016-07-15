/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 16 September 2015 11:02:36  IST
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
	double a,b;
	cin >> a >> b;
	double k1= (a+b)/(2*b);
	double k2 = (a-b)/(2*b);
	double x1,x2;
	x1 = (a+b)/(2*k1);
	x2 = (a-b)/(2*k2);
	if(a<b)
		cout << "-1" << endl;
	else
		printf("%.9lf\n",min(x1,x2));
	return 0;
}
