/*
 * =====================================================================================
 *
 *       Filename:  sumpair.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 19 July 2015 09:43:44  IST
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
		long long int n,d;
		cin >> n >> d;
		long long int a[n];
		for(long long int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		long long int count=0;
		long long int i=n-1;
		while(i>0)
		{
			if(a[i]-a[i-1] < d)
			{
				count += a[i]+a[i-1];
				i--;
			}
			i--;
		}
		cout << count << endl;
	}
	return 0;
}
