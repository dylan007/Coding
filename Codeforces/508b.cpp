/*
 * =====================================================================================
 *
 *       Filename:  508b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 09 July 2016 10:18:06  IST
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
	int f=0;
	for(int i=0;i<a.length();i++)
	{
		if((int(a[i])-int('0'))%2 == 0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		cout << "-1" << endl;
		return 0;
	}
	f=-1;
	for(int i=0;i<a.length()-1;i++)
	{
		int x = int(a[i])-int('0');
		int y = int(a[a.length()-1])-int('0');
		if((x%2 == 0) && x<y)
		{
			f = i;
			break;
		}
	}
	//cout << f << endl;
	if(f!=-1)
	{
		swap(a[f],a[a.length()-1]);
		cout << a << endl;
		return 0;
	}
	f=-1;
	for(int i=a.length()-2;i>=0;i--)
	{
		int x = int(a[i])-int('0');
		int y = int(a[a.length()-1])-int('0');
		if((x%2 == 0) && x>y)
		{
			f=i;
			break;
		}
	}
	swap(a[f],a[a.length()-1]);
	cout << a << endl;
	return 0;
}
