/*
 * =====================================================================================
 *
 *       Filename:  johny.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 08 June 2016 02:05:16  IST
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
		int k,n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		cin >> k;
		int x;
		x = a[k-1];
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			if(x == a[i])
			{
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}
