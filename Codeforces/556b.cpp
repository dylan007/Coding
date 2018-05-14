/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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
	long long int n,k;
	cin >> n >> k;
	long long int x=1;
	for(long long int i=0;i<k;i++)
	{
		long long int l;
		cin >> l;
		long long int a[l];
		for(long long int j=0;j<l;j++)
			cin >> a[j];
		if(a[0]==1)
		{
			//cout << "#1" << endl;
			long long int j=1;
			while((a[j] == j+1) && j<l)
				j++;
			x = a[j-1];
			//cout << j << endl;
		}
	}
	//cout << x << endl;
	cout << 2*n - 2*x - k + 1 << endl;
	return 0;
}
