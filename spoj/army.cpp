/*
 * =====================================================================================
 *
 *       Filename:  army.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 03 June 2016 02:23:25  IST
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
		int ng,nm,x,gmax=0,mgmax=0;
		cin >> ng >> nm;
		while(ng--)
		{
			cin >> x;
			gmax = max(x,gmax);
		}
		while(nm--)
		{
			cin >> x;
			mgmax = max(x,mgmax);
		}
		if(gmax >= mgmax)
			cout << "Godzilla" << endl;
		else if(gmax < mgmax)
			cout << "MechaGodzilla" << endl;
		else
			cout << "uncertain" << endl;
	}
	return 0;
}
