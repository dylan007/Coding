/*
 * =====================================================================================
 *
 *       Filename:  marcha1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 June 2016 05:14:07  IST
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
		int n,m;
		cin >> n >> m;
		int val[n],f=0;
		for(int i=0;i<n;i++)
			cin >> val[i];
		for(int i=1;i<pow(2,n);i++)
		{
			int sum=0;
			for(int j=0;j<n;j++)
				sum += (val[j]*((i>>j)&1));
			if(sum == m)
			{
				//cout << i << endl;
				cout << "Yes" << endl;
				f = 1;
				break;
			}
		}
		if(f==0)
			cout << "No" << endl;
	}
	return 0;
}
