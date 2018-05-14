/*
 * =====================================================================================
 *
 *       Filename:  chefrp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 May 2015 03:12:02  IST
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
		int min=INT_MAX;
		int i,x;
		int sum=0;
		for(i=0;i<n;i++)
		{
			cin >> x;
			min = min<x?min:x;
			sum+=x;
		}
		if(min<2)
			cout << "-1\n";
		else
			cout << sum-(min-2) << endl;
	}
	return 0;
}
