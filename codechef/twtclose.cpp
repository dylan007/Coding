/*
 * =====================================================================================
 *
 *       Filename:  twtclose.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 16 May 2015 09:04:25  IST
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
	int n,q;
	cin >> n >> q;
	int check[n];
	memset(check,0,4*n);
	int count=0;
	for(int i=0;i<q;i++)
	{
		string com;
		cin >> com;
		int x;
		if(com.length()==5)
		{
			cin >> x;
			if(check[x-1]==1)
			{
				count--;
				check[x-1]=0;
			}
			else
			{
				count++;
				check[x-1]=1;
			}
		}	
		else
		{
			memset(check,0,4*n);
			count=0;
		}
		cout << count << endl;
	}
	return 0;
}
