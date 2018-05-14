/*
 * =====================================================================================
 *
 *       Filename:  treeroot.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 16 May 2015 09:27:04  IST
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
		int n;
		cin >> n;
		int sum=0;
		int x,y;
		while(n--)
		{
			cin >> x >> y;
			sum += x-y;
		}
		cout << sum << endl;
	}
	return 0;
}
