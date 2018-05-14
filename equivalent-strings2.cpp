/*
 * =====================================================================================
 *
 *       Filename:  equivalent-strings2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 22 March 2015 12:17:43  IST
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
		string a,b;
		cin >> a >> b;
		int q;
		cin >> q;
		while(q--)
		{
			int i,j,k;
			cin >> i >> j >> k;
			i--;
			j--;
			int f=0;
			for(int p=i;p<(i+k);p++)
			{	
				for(int l=j;l<(j+k);l++)
				{
					if(!((a[p]==a[l] && b[p-i+j]==b[l-i+j]) && (a[p]!=a[l] && b[p-i+j]!=b[l-i+j])))
					{
						f=1;
						break;
					}
				}
				if(f==1)
					break;
			}
			if(f==0)
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
	return 0;
}
