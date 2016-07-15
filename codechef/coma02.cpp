/*
 * =====================================================================================
 *
 *       Filename:  coma02.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 21 March 2015 11:27:29  IST
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
		int n,m,o;
		cin >> n >> m >> o;
		int count=0,x;
		int f=0;
		for(int i=0;i<n;i++)
		{
			cin >> x;
			if(i==0)
				f = (x>o);
			count += (x>o);
		}
		count = count>m?m:count;
		count = (f==1)?count:-1;
		cout << count << endl;
	}
	return 0;
}
