/*
 * =====================================================================================
 *
 *       Filename:  candy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 20 June 2015 07:11:33  IST
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
	int n;
	cin >> n;
	while(n!=-1)
	{
		long long int a[n],sum=0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		if(sum%n != 0)
			cout  << "-1" << endl;
		else
		{
			sum /= n;
			long long int count=0;
			for(int i=0;i<n;i++)
				count += abs(sum-a[i]);
			if(count%2 == 0)
				cout << count/2 << endl;
		}
		cin >> n;
	}
	return 0;
}
