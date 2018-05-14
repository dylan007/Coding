/*
 * =====================================================================================
 *
 *       Filename:  hangover.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 June 2016 08:43:40  IST
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
	float x;
	cin >> x;
	while(x>0)
	{
		float y,t;
		t = 2.00;
		y = x;
		while(y>0)
		{
			y -= 1/t;
			t = t+1*(y>0);
		}
		cout << int(t-1) << " card(s)" << endl;
		cin >> x;
	}
	return 0;
}
