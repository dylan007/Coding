/*
 * =====================================================================================
 *
 *       Filename:  581a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 02 July 2016 10:37:11  IST
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
	int a,b;
	cin >> a >> b;
	cout << min(a,b) << " " << (max(a,b)-min(a,b))/2 << endl;
	return 0;
}
