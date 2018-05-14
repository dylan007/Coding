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
	int n;
	cin >> n;
	string a;
	cin >> a;
	int check[26],count=0;
	memset(check,0,sizeof(check));
	for(int i=0;i<a.length();i++)
	{
		count += (check[a[i]-'a']==0);
		check[a[i]-'a']=1;
	}
	if(count < n)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		memset(check,0,sizeof(check));
		check[a[0]-'a']=1;
		n--;
		int i;
		cout << a[0];
		for(i=1;i<a.length();i++)
		{
			if(n==0)
				break;
			if(check[a[i]-'a']==0)
			{
				cout << endl;
				check[a[i]-'a']=1;
				n--;
			}
			cout << a[i];
		}
		for(;i<a.length();i++)
			cout << a[i];
		
		cout << endl;
	}
	return 0;
}
