/*
 * =====================================================================================
 *
 *       Filename:  677a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 02:36:18  IST
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
	int n,h;
	cin >> n >> h;
	int x;
	int wid=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		wid += 2*(x>h)+1*(x<=h);
	}
	cout << wid << endl;
	return 0;
}
