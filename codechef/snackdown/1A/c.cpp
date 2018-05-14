/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 23 May 2015 02:48:55  IST
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
		int n;
		cin >> n;
		int a[n];
		int sum=0,flag=0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			sum += a[i];
			if(a[i]==n)
				flag=1;
		}
		if(sum!=n || flag==1)
			cout << "-1" << endl;
		else
		{
			int i,j;
			for(int i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(j!=i)
					{
						if(a[j]>0)
						{
							cout << j+1 << " ";
							a[j]--;
							break;
						}
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}
