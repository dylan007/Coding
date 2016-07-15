/*
 * =====================================================================================
 *
 *       Filename:  horses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 June 2016 05:31:59  IST
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
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		int diff=INT_MAX;
		for(int i=0;i<n-1;i++)
			diff = min(diff,a[i+1]-a[i]);
		cout << diff << endl;
	}
	return 0;
}
