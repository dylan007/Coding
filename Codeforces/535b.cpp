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
	string n;
	cin >> n;
	int ans;
	ans = 2*(pow(2,n.length()-1)-1);
	int count=0;
	for(int i=0;i<n.length();i++)
		count += (n[i]=='7')?pow(2,n.length()-1-i):0;
	cout << ans+count+1 << endl;
	return 0;
}
