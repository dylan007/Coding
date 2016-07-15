/*
 * =====================================================================================
 *
 *       Filename:  cops.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 19 July 2015 09:35:30  IST
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
	while(T--)
	{
		int check[100];
		memset(check,0,sizeof(check));
		int m,x,y;
		cin >> m >> x >> y;
		for(int i=0;i<m;i++)
		{
			int pos;
			cin >> pos;
			int start, end;
			start = (pos-x*y-1 >= 0) ? pos-x*y-1 : 0;
			end = (pos+x*y-1 < 100 ) ? pos+x*y-1 : 100;
			for(int j=start;j<=end;j++)
				check[j]=1;
		}
		int count=0;
		for(int i=0;i<100;i++)
			count += check[i]==0;
		cout << count << endl;
	}
	return 0;
}
