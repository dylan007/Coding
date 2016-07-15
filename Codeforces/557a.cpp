/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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
	int x1,x2,x3;
	int n;
	cin >> n;
	int min[3],max[3];
	for(int i=0;i<3;i++)
		cin >> min[i] >> max[i];
	x1 = (n-min[1]-min[2])>max[0] ? max[0]:(n-min[1]-min[2]);
	n -= x1;
	x2 = (n-min[2])>max[1] ? max[1]:(n-min[2]);
	n -= x2;
	x3 = n;
	cout << x1 << " " << x2 << " " << x3 << endl;
	return 0;
}
