/*
 * =====================================================================================
 *
 *       Filename:  cbarg.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 05 June 2015 06:44:33  IST
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
		long long int x,temp,n;
		long long int count=0;
		cin >> n;
		n--;
		cin >> temp;
		count = temp;
		while(n--)
		{
			cin >> x;
			//cout << abs(x-temp) << " " << temp << endl;
			if(x>temp)
				count += abs(x-temp);
			temp = x;
		}
		cout << count << endl;
	}
}
