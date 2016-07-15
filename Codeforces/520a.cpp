/*
 * =====================================================================================
 *
 *       Filename:  520a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 06 July 2015 09:05:22  IST
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
	int l;
	cin >> l;
	string a;
	cin >> a;
	int check[26];
	int ans=0;
	memset(check,0,sizeof(check));
	for(int i=0;i<l;i++)
	{
		int t;
		t = int(a[i]);
		if(t>=int('A') && t<=int('Z'))
			t -= int('A');
		else if(t>=int('a') && t<=int('z'))
			t -= int('a');
		if(check[t]==0)
			ans++;
		check[t]++;
	}
	if(ans == 26)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
