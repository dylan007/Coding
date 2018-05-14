/*
 * =====================================================================================
 *
 *       Filename:  sum-of-absolutes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 July 2015 06:17:06  IST
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
	int n,q;
	cin >> n >> q;
	int a[n];
	memset(a,0,sizeof(a));
	int x;
	cin >> x;
	a[0]=abs(x);
	for(int i=1;i<n;i++)
	{
		cin >> x;
		a[i] = abs(a[i-1]+x);
	//	cout << a[i] << " " << i << endl;
	}
	int y;
	while(q--)
	{
		cin >> x >> y;
		x--;
		y--;
		int t;
		if(x==0)
			t = a[y];
		else
			t = a[y]-a[x]+abs(a[x]-a[x-1]);
		if(t%2 == 0)
			cout << "Even" << endl;
		else
			cout << "Odd" << endl;
	}
	return 0;
}
