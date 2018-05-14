/*
 * =====================================================================================
 *
 *       Filename:  buying2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 08 June 2016 04:39:52  IST
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
		int n,x,y,f=0;
		cin >> n >> x;
		int sum=0,m=INT_MAX;
		while(n--)
		{
			cin >> y;
			sum += y;
			m = m<y?m:y;
		}
		if(x>sum || (sum/x == (sum-m)/x))
			cout << -1 << endl;
		else
			cout << sum/x << endl;
	}
}
