/*
 * =====================================================================================
 *
 *       Filename:  pinoch1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 May 2015 09:53:07  IST
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
		int n,x;
		cin >> n;
		int a[n];
		int count=0;
		cin >> x;
		int y;
		int max=INT_MIN;
		for(int i=1;i<n;i++)
		{
			cin >> y;
			if(x==y)
				count++;
			else
			{
				max = max>count?max:count;
				count=0;
			}
			x=y;
		}
		max = max>count?max:count;
		cout << max << endl;
	}
	return 0;
}
