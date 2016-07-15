/*
 * =====================================================================================
 *
 *       Filename:  gdog.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 26 July 2015 11:06:52  IST
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
		int n,k;
		cin >> n >> k;
		int max=0;
		max = (k<(n-1))?k:(n-1);
		max = n%max;
		cout << max << endl;
	}
	return 0;
}
