/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 11 October 2015 04:44:30  IST
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
	int n;
	cin >> n;
	int x;
	int c=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		c+=(x%2 == 0);
	}
	if(c>n-c)
		cout << "READY FOR BATTLE" << endl;
	else
		cout << "NOT READY" << endl;
	return 0;
}
