/*
 * =====================================================================================
 *
 *       Filename:  688a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 09 July 2016 09:14:13  IST
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
	int n,d;
	cin >> n >> d;
	int temp=0,m=0;
	for(int i=0;i<d;i++)
	{
		string a;
		cin >> a;
		int f=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]=='0')
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			temp++;
			m = max(m,temp);
		}
		else
			temp=0;
	}
	cout << m << endl;
	return 0;
}
