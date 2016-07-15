/*
 * =====================================================================================
 *
 *       Filename:  devarray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 June 2016 04:06:35  IST
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
	int n,q;
	cin >> n >> q;
	int x,min=0,max=INT_MAX;
	cin >> x;
	min = x;
	max = x;
	n--;
	while(n--)
	{
		cin >> x;
		min = min<=x?min:x;
		max = max>=x?max:x;
	}
	//cout << min << " " << max << endl;
	while(q--)
	{
		cin >> x;
		if(x>=min && x<=max)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
