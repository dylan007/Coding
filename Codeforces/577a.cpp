/*
 * =====================================================================================
 *
 *       Filename:  577a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 02 July 2016 08:20:42  IST
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
	int n,x;
	cin >> n >> x;
	int count=0;
	for(int i=1;i<=n;i++)
		count += (x%i == 0)&&(x/i<=n);
	cout <<  count << endl;
	return 0;
}
