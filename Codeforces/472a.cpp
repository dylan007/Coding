/*
 * =====================================================================================
 *
 *       Filename:  472a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 July 2016 10:46:46  IST
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
	if(n%2 == 0)
		cout << "4" << " " << n-4 << endl;
	else
		cout << "9" << " " << n-9 << endl;
	return 0;
}
