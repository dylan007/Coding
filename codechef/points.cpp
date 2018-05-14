/*
 * =====================================================================================
 *
 *       Filename:  points.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 17 May 2015 10:07:19  IST
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

int sorted(pair &a,pair &b)
{
	if(a.first > b.first)
		return 1;
	else if(a.first < b.first)
		return -1;
	else
	{
		if(a.second > b.second)
			return -1;
		else if(a.second < b.second)
			return 1;
		else
			return 0;
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		pair a[n];
		for(int i=0;i<n;i++)
			cin >> a[i].first >> a[i].second;
		sort(a,a+n,sorted);
		for(int i=0;i<n;i++)
			cout << a[i].first << a[i].second << endl;
	}
	return 0;
}
