/*
 * =====================================================================================
 *
 *       Filename:  588a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 15 July 2016 04:20:05  IST
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
	int price=INT_MAX;
	int a,p;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin >> a >> p;
		price = min(price,p);
		ans += price*a;
	}
	cout << ans << endl;
	return 0;
}
