/*
 * =====================================================================================
 *
 *       Filename:  racewars.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 15 May 2015 08:26:04  IST
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
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		sort(a,a+n,std::greater<int>());
		sort(b,b+n,std::greater<int>());
		int i;
		int count=0;
		int j=0;
		for(i=0;i<n;i++)
		{
			for(;j<n;j++)
			{
		//		cout << a[i] << " " << b[j] << " " << count << endl; 
				if(a[i]>b[j])
				{
					count++;
					j++;
					break;
				}
			}	
		}
		cout << count << endl;
	}
	return 0;
}
