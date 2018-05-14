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
	int n;
	cin >> n;
	int ver[n],hor[n];
	memset(ver,0,sizeof(ver));
	memset(hor,0,sizeof(hor));
	for(int i=1;i<= n*n;i++)
	{
		int x,y;
		cin >> x >> y;
		if(ver[y-1]==0 && hor[x-1]==0)
		{
			cout << i << " ";
			ver[y-1] = 1;
			hor[x-1] = 1;
		}
	}
	cout << endl;
	return 0;
}
