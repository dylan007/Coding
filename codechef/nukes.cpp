/*
 * =====================================================================================
 *
 *       Filename:  nukes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 07 June 2016 05:35:44  IST
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
	int a,n,k;
	cin >> a >> n >> k;
	n++;
	for(int i=0;i<k-1;i++)
	{
		cout <<	a%n << " " ;
		a /= n;
	}
	cout << a%n << endl;
	return 0;
}
