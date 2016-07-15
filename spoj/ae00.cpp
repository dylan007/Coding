/*
 * =====================================================================================
 *
 *       Filename:  ae00.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 13 March 2015 05:42:16  IST
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
	int n;
	cin >> n;
	int i,j;
	int count=0;
	for(i=1;i<=sqrt(n);i++)
	{
		for(j=i+1;i*j<=n;j++)
			count++;
	}
	count += sqrt(n);
	cout << count << endl;
	return 0;
}
