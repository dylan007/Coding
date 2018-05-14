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
	int l;
	cin >> l;
	string a,b;
	cin >> a >> b;
	int ans=0;
	for(int i=0;i<l;i++)
	{
		int x = int(a[i])-int('a');
		int y = int(b[i])-int('a');
		x = abs(x-y);
		if(x > abs(9-x))
			ans += abs(9-x+1);
		else
			ans += x;
	}
	cout << ans;
	return 0;
}
