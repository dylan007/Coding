/*
 * =====================================================================================
 *
 *       Filename:  651a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 July 2016 05:31:06  IST
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
	ll x,y;
	cin >> x >> y;
	ll time = 0;
	if(x==1 && y==1)
	{
		cout << "0" << endl;
		return 0;
	}
	while(x>0 && y>0)
	{
		if(x==1)
		{
			x++;
			y-=2;
		}
		else if(y==1)
		{
			y++;
			x-=2;
		}
		else if(x>y)
		{
			y++;
			x-=2;
		}
		else if(x<=y)
		{
			y-=2;
			x++;
		}
		x = x>100?100:x;
		y = y>100?100:y;
		time++;
	}
	cout << time << endl;
	return 0;
}
