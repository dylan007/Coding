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
	int T;
	cin >> T;
	int sum=0;
	while(T--)
	{
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		sum += abs((x2-x1+1)*(y2-y1+1));
	}
	cout << sum << endl;
	return 0;
}
