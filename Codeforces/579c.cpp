/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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
	double x;
	if(a<b)
		cout << "-1" << endl;
	else
	{
		if((int)(a-b)%2 == 0 && a!=b)
			x = a-b;
		else
			x = a+b;
		while(x>1)
			x /= 2;
		x = x*((x<1)?2:1);
		printf("%.9lf\n",x);
	}
	return 0;
}
