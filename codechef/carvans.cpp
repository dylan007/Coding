/*
 * =====================================================================================
 *
 *       Filename:  carvans.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 08 June 2016 03:58:53  IST
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
		int num=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]<=a[i-1])
				num++;
			else
				a[i] = a[i-1];
		}
		cout << num << endl;
	}
	return 0;
}
