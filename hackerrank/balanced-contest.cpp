/*
 * =====================================================================================
 *
 *       Filename:  balanced-contest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 23 July 2015 10:34:32  IST
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
	pair<int,int> a[5];
	for(int i=0;i<5;i++)
	{
		int x,y;
		cin >> x >> y;
		a[i].first = x;
		a[i].second = y;
	}
	sort(a,a+5);
	int flag=0;
	for(int i=1;i<5;i++)
	{
		flag = flag||!(a[i].first>a[i-1].first && a[i].second>a[i-1].second);
	}
	if(flag == 0)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	return 0;
}
