/*
 * =====================================================================================
 *
 *       Filename:  x.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 22 March 2015 09:28:51  IST
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

int count(string a,string b)
{
	int i;
	int count;
	for(i=0;i<a.len();i++)
	{
		count+= (a[i]!=b[i]);
	}
	return i;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int check[26];
		memset(check,0,4*26);
		int len;
		cin >> len;
		string a;
		string check;
		check=a;
		string ans=a;
		cin >> a;
		int f=0;
		while(prev_permutation(a.begin(),a.end()))
		{
			if(count(a,check)==1)
			{
				f=1;
				ans=a;
			}
		}
		cout << ans <<endl;
	}
	return 0;
}
