/*
 * =====================================================================================
 *
 *       Filename:  amr10f.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 April 2015 06:41:14  IST
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
		int n,a,d;
		cin >> n >> a >> d;
		cout << (n*(2*a + (n-1)*d))/2 << endl;
	}
	return 0;
}
