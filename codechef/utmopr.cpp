/*
 * =====================================================================================
 *
 *       Filename:  utmopr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 21 June 2015 09:33:47  IST
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
typedef long long int ll;


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll n,k;
		cin >> n >> k;
		ll sum=0,x;
		while(n--)
		{
			cin >> x;
			sum += x;
		}
		k--;
		while(k--)
		{
			sum += (sum+1);
		}
		sum++;
		if(sum%2 == 0)
			cout << "even" << endl;
		else 
			cout << "odd" << endl;
	}
	return 0;
}
