/*
 * =====================================================================================
 *
 *       Filename:  divsum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 April 2015 10:58:56  IST
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
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		if(x==1)
			cout << "0\n";
		else
		{
			int ans=1;
			int i=2;
			while(i<=sqrt(x))
			{
				if(x%i == 0)
					ans += i+(i*i != x)*(x/i);
				i++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
