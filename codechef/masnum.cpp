/*
 * =====================================================================================
 *
 *       Filename:  masnum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 May 2015 11:01:12  IST
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

long long int power(long long int x)
{
	long long int r=1;
	long long int t=10;
	while(x>0)
	{
		x--;
		r = (r << 3) + (r << 1);
	}
	return r;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long int n;
		cin >> n;
		if(n&1 == 1)
			cout << "0\n";
		else
		{
			long long int x;
			x = n/2;
			cout << "9";
			for(int i=0;i<(x-1);i++)
				cout << "0";
			cout << endl;
		}
	}
	return 0;
}
