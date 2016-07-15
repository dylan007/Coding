/*
 * =====================================================================================
 *
 *       Filename:  amcs05.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 05 July 2015 04:20:16  IST
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
typedef long long int ll;
typedef unsigned long long int ull;


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string a,b;
		cin >> a >> b;
		int x; 
		cin >> x;
		int c1[26],c2[26];
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<a.length();i++)
			c1[int(a[i])-int('a')]++;
		for(int i=0;i<b.length();i++)
			c2[int(b[i])-int('a')]++;
		int ans=0;
		for(int i=0;i<26;i++)
			ans += abs(c2[i]-c1[i]);
		if(ans <= x)
			cout <<"YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
