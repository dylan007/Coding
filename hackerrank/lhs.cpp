/*
 * =====================================================================================
 *
 *       Filename:  lhs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 28 August 2015 09:33:24  IST
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
		int a[n],max=0,x;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			max = max<a[i]?a[i]:max;
		}
		sort(a,a+n);
		int c=0;
		for(int i=(n-1);a[i]==max;i--)
			c++; 
		cout << c << endl;
	}
	return 0;
}
