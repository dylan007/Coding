/*
 * =====================================================================================
 *
 *       Filename:  conflip.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 June 2016 05:52:14  IST
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
		int g;
		cin >> g;
		while(g--)
		{
			int i,n,q;
			cin >> i >> n >> q;
			if(i==q)
				cout << n/2 << endl;
			else
				cout << (n+1)/2 << endl;
		}
	}
	return 0;
}
