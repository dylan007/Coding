/*
 * =====================================================================================
 *
 *       Filename:  580a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 22 September 2015 10:02:24  IST
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
	int x,y;
	cin >> x;
	int count=1;
	int max=1;
	n--;
	for(int i=0;i<n;i++)
	{
		cin >> y;
		if(x<=y)
			count++;
		else
		{
			max = max<count?count:max;
			count = 1;
		}
	//	cout << x << " " << y << " "  << count << endl;
		x = y;
	}
	max = max<count?count:max;
	cout << max << endl;
	return 0;
}
