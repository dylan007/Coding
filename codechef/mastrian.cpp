/*
 * =====================================================================================
 *
 *       Filename:  mastrian.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 May 2015 11:11:26  IST
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
#define MAX 1000000007

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long int n,m,k;
		cin >> n >> m;
		if(n>m)
			swap(n,m);
		k = m-n;
		k = k%MAX;
		n = n%MAX;
		m = m%MAX;
		long long int ans;
		ans = ((n*(n+1)*(2*n+1))%MAX)/6 + ((k*(n+1)*n)%MAX)/2;
		cout << (ans%MAX)*2 << endl;
	}
	return 0;
}
