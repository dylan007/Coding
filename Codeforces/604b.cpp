/*
 * =====================================================================================
 *
 *       Filename:  604b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 07 December 2015 08:20:00  IST
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
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int max=0;
	if(k>=n)
		cout << a[n-1] << endl;
	else
	{
		max=0;
		for(int i=(2*(n-k));i<n;i++)
			max = max>a[i]?max:a[i];
		for(int i=0;i<(2*(n-k));i++)
			max = max>(a[i]+a[2*(n-k)-i-1])?max:(a[i]+a[2*(n-k)-i-1]);
		cout << max <<endl;
	}
	return 0;
}
