/*
 * =====================================================================================
 *
 *       Filename:  680a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 11 July 2016 09:00:13  IST
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
	int a[5];
	for(int i=0;i<5;i++)
		cin >> a[i];
	sort(a,a+5);
	int f=-1;
	int sum=a[0];
	for(int i=1;i<5;i++)
	{
		//cout << a[i] << " "; 
		if(a[i]==a[i-1])
			f=a[i];
		sum += a[i];
	}
	int count=0;
	if(f!=-1)
	{
		for(int i=0;i<5;i++)
			count += (f==a[i]);
	}
	//cout << endl << sum << endl;
	count = min(3,count);
	if(f==-1)
		cout << sum << endl;
	else
		cout << sum-count*f << endl;
	return 0;
}
