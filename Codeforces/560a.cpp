/*
 * =====================================================================================
 *
 *       Filename:  560a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 01:46:31  IST
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
	int x;
	int f=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x==1)
			f=1;
	}
	if(f==1)
		cout << "-1" << endl;
	else
		cout << "1" << endl;
	return 0;
}
