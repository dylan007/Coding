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
	string a,b;
	cin >> a >> b;
	int i,j,l1,l2;
	l1 = a.length();
	l2 = b.length();
	int dist=0;
	for(i=0;i<l1;i++)
		dist += (a[i]!=b[i]);
	if(dist%2 == 1)
		cout << "impossible\n" ;
	else
	{
		string ans;
		int count=0;
		for(i=0;i<l1;i++)
		{
			if(a[i]!=b[i])
			{
				if(count < dist/2)
					ans += a[i];
				else
					ans += b[i];
				count++;
			}
			else
				ans += a[i];
		}	
		cout << ans << endl;
	}
	return 0;
}
