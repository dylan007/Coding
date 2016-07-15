/*
 * =====================================================================================
 *
 *       Filename:  intest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 12 June 2016 08:14:38  IST
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
	int x,T,k,s=0;
	cin >> T >> k;
	while(T--)
	{
		scanf("%d",&x);
		s += (x%k == 0);
	}
	printf("%d\n",s);
}
