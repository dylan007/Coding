/*
 * =====================================================================================
 *
 *       Filename:  672a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 July 2016 05:43:06  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s="1";
	for(int i=2;i<=1000;i++)
	{
		stringstream ss;
		ss << i;
		string a;
		a = ss.str();
		s += a;
	}
	cout << s[n-1] << endl;
	return 0;
}
