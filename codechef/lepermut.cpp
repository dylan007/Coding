/*
 * =====================================================================================
 *
 *       Filename:  lepermut.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 11 June 2016 10:32:00  IST
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
		int n_loc=0,n_tot=0;
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=1;i<n;i++)
			n_loc += (a[i-1]>a[i]);
		for(int i=0;i<(n-1);i++)
		{
			for(int j=i+1;j<n;j++)
				n_tot += (a[i]>a[j]);
		}
		if(n_tot == n_loc)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
