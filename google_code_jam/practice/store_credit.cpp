/*
 * =====================================================================================
 *
 *       Filename:  store_credit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 12 July 2016 02:01:10  IST
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
	for(int k=1;k<=T;k++)
	{
		int n,c;
		cin >> c >> n;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		int x=-1,y=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(c == (a[i]+a[j]))
				{
					x = min(i,j)+1;
					y = max(i,j)+1;
					break;
				}
			}
			if(x>=0)
				break;
		}
		cout << "Case #" << k << ": " << x << " " << y << endl;
	}
	return 0;
}
