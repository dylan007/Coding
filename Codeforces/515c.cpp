/*
 * =====================================================================================
 *
 *       Filename:  515c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 11 July 2016 05:00:13  IST
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
	int n;
	cin >> n;
	int a[10] = {0};
	string num;
	cin >> num;
	for(int i=0;i<n;i++)
	{
		switch(num[i])
		{
			case '0':
			case '1':
				break;
			case '2':
				a[2]++;
				break;
			case '3':
				a[3]++;
				break;
			case '4':
				a[3]++;
				a[2]+=2;
				break;
			case '5':
				a[5]++;
				break;
			case '6':
				a[5]++;
				a[3]++;
				break;
			case '7':
				a[7]++;
				break;
			case '8':
				a[7]++;
				a[2]+=3;
				break;
			case '9':
				a[7]++;
				a[3]+=2;
				a[2]++;
				break;
		}
	}
	string s;
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout << i;
			a[i]--;
		}
	}
	cout << s << endl;
	return 0;
}
