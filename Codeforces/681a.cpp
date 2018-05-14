/*
 * =====================================================================================
 *
 *       Filename:  681a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 July 2016 06:01:15  IST
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
	int x;
	cin >> x;
	string s;
	int flag=0;
	int a,b;
	while(x--)
	{
		cin >> s;
		cin >> a >> b;
		if(a>=2400 && b>a)
			flag = 1;
	}
	if(flag==1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
