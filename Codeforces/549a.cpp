/*
 * =====================================================================================
 *
 *       Filename:  549a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 July 2016 03:44:21  IST
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


int main()
{
	ll n,m;
	cin >> n >> m;
	char a[n][m],c;
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
			cin >> a[i][j];
	}
	/*for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
			cout << a[i][j];
		cout << endl;
	}*/
	for(ll i=0;i<(n-1);i++)
	{
		for(ll j=0;j<(m-1);j++)
		{
			char s[4];
			s[0] = a[i][j];
			s[1] = a[i+1][j];
			s[2] = a[i][j+1];
			s[3] = a[i+1][j+1];
			sort(s,s+4);
			if(s[0]=='a' && s[1]=='c' && s[2]=='e' && s[3]=='f')
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
