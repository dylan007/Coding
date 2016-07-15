/*
 * =====================================================================================
 *
 *       Filename:  sizecon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 11 August 2015 08:06:29  IST
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
	int sum=0;
	while(T--)
	{
		int x;
		cin >> x;
		sum += x*(x>0);
	}
	cout << sum << endl;
	return 0;
}
