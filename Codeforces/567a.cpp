/*
 * =====================================================================================
 *
 *       Filename:  567a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 02 July 2016 09:18:57  IST
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
	sort(a,a+n);
	cout << abs(a[1]-a[0]) << " " << abs(a[0]-a[n-1]) << endl;
	for(int i=1;i<(n-1);i++)
		cout << min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1])) << " " << max(abs(a[i]-a[0]),abs(a[i]-a[n-1])) << endl;
	cout << abs(a[n-1]-a[n-2]) << " " << abs(a[n-1]-a[0]) << endl;
	return 0;
}
