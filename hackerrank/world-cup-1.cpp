/*
 * =====================================================================================
 *
 *       Filename:  world-cup-1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 13 September 2015 11:37:40  IST
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
	int a[10];
	for(int i=0;i<10;i++)
		cin >> a[i];
	sort(a,a+10);
	//cout << a[0] << endl;
	int s1=0,s2=0;
	for(int i=9;i>3;i--)
	{
		s1 += (i%2)*a[i];
		s2 += !(i%2)*a[i];
	}

	int max = (s1>s2)?s1:s2; 
	cout << max << endl;
	return 0;

}
