/*
 * =====================================================================================
 *
 *       Filename:  659a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 12 July 2016 08:53:56  IST
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
	int n,a,b;
	cin >> n >> a >> b;
	a = a+b;
	a = a%n;
	if(a<0)
		a = n+a;
	if(a==0)
		cout << n << endl;
	else
		cout << a << endl;
	return 0;
}
