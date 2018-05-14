/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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
	long long int n,x;
	string s;
	cin >> s;
	long long int l;
	l = s.length();
	n = atoll(s.c_str());
	long long int sum=0;
	sum += l*(n -pow(10,l-1) + 1);
	l--;
	while(l>0)
	{
		sum += 9*l*(pow(10,l-1));
		l--;
	}
	cout << sum << endl;
	return 0;
}
