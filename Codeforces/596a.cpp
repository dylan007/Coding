/*
 * =====================================================================================
 *
 *       Filename:  596a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 July 2016 10:00:41  IST
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

int n;
set<int> a, b;

int value(set<int>& s) 
{
	return (*s.rbegin())-(*s.begin());
}

int main(void)
{
	cin >> n;
	for (int i=0; i<n; i++) 
	{
		int x, y;
		cin >> x >> y;
		a.insert(x);
		b.insert(y);
	}
	if (a.size()!=2 || b.size()!=2)
		cout << "-1\n";
	else
		cout << value(a)*value(b) << "\n";
	return 0;
}
