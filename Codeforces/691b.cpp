/*
 * =====================================================================================
 *
 *       Filename:  691a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 13 July 2016 09:20:08  IST
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

int check(string a)
{
	int l=a.length();
	int f=0;
	for(int i=0;i<l/2;i++)
	{
		if(a[i]=='b')
		{
			f = !(a[l-i-1]=='d');
			if(f==1)
				return 0;
		}
		else if(a[i]=='d')
		{
			f = !(a[l-i-1]=='b');
			if(f==1)
				return 0;
		}
		else if(a[i]=='p')
		{
			f = !(a[l-i-1]=='q');
			if(f==1)
				return 0;
		}
		else if(a[i]=='q')
		{
			f = !(a[l-i-1]=='p');
			if(f==1)
				return 0;
		}
		else if(a[i]==a[l-i-1])
		{
			switch(a[i])
			{
				case 'A':
				case 'H':
				case 'I':
				case 'M':
				case 'O':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'o':
				case 'v':
				case 'w':
				case 'x':
					break;
				default:
					return 0;
			}
		}
		else
			return 0;
	}
	if(l%2 != 0)
	{
		switch(a[l/2])
		{
			case 'A':
			case 'H':
			case 'I':
			case 'M':
			case 'O':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'o':
			case 'v':
			case 'w':
			case 'x':
				return 1;
			default:
				return 0;
		}
	}
	return 1;
}

int main()
{
	string a;
	cin >> a;
	if(check(a)==1)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
	return 0;
}
