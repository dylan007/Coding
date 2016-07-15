/*
 * =====================================================================================
 *
 *       Filename:  550a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 11 July 2016 09:13:44  IST
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
	string a;
	cin >> a;
	int l = a.length();
	int f1=0,f2=0;
	for(int i=0;i<(l-1);i++)
	{
		if(int(a[i])==int('B'))
		{
			if(int(a[i+1])==int('A'))
			{
				i++;
				f1=1;
				continue;
			}
		}
		else if(int(a[i])==int('A'))
		{
			if(int(a[i+1])==int('B'))
			{
				i++;
				f2=1;
				continue;
			}
		}
	}
	if(f1 && f2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
