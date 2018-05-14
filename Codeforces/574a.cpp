/*
 * =====================================================================================
 *
 *       Filename:  574a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 16 September 2015 04:35:38  IST
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
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a+1,a+n);
	int count=0;
	while(a[0]<=a[n-1])
	{
		count++;
		a[n-1]--;
		a[0]++;
		sort(a+1,a+n);
	}
	cout << count << endl;
	return 0;
}
