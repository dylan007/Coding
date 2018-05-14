/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 11 October 2015 04:44:30  IST
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
		int n,k;
		cin >> n >> k;
		if(k > (n/2))
			cout << "-1" << endl;
		else
		{
			int i;
			for(i=k+1;i<=n;i++)
				cout << i << " ";
			for(i=1;i<k;i++)
				cout << i << " ";
			if(i<=k) 
				cout << i ;
			cout << endl;
		}
	}
	return 0;
}
