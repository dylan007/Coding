/*
 * =====================================================================================
 *
 *       Filename:  675a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 12 July 2016 10:23:54  IST
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
	int a,b,c;
	cin >> a >> b >> c;
	if(c==0)
	{
		if(a==b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if(((b-a)%c == 0) && ((b-a)/c >= 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
