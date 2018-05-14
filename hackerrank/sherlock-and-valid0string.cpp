/*
 * =====================================================================================
 *
 *       Filename:  sherlock-and-valid0string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 23 June 2015 10:03:02  IST
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
	int check[26];
	memset(check,0,sizeof(check));
	int count=0;
	for(int i=0;i<a.length();i++)
	{
		check[int(a[i])-int('a')]++;
		count += (check[int(a[i])-int('a')] == 0);
	}
	sort(check,check+26);
	reverse(check,check+26);
	int ans=0;
	for(int i=0;i<26;i++)
		ans += abs(count-check[i]);
	if(ans > 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
