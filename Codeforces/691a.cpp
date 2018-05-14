/*
 * =====================================================================================
 *
 *       Filename:  691b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 13 July 2016 09:20:31  IST
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
	int n,x;
	cin >> n;
	int f=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		f += !x;
	}
	if(n==1)
	{
		if(f==0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if(f!=1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
