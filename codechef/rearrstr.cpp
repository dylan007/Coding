/*
 * =====================================================================================
 *
 *       Filename:  rearrstr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 24 May 2015 09:41:26  IST
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
		string a;
		cin >> a;
		int max=0;
		int check[26];
		memset(check,0,sizeof(check));
		int flag=0;
		for(int i=0;i<a.length();i++)
		{
			check[int(a[i])-97]++;
			if(max < check[int(a[i])-97])
			{
				max = (check[int(a[i])-97] > max)?check[int(a[i])-97]:max;
				flag=int(a[i])-97;
			}
		}
		int n=a.length();
		if(n-max>=(max-1))
		{
			int temp=flag;
			cout << char(flag+97);
			check[flag]--;
			for(int i=1;i<n;i++)
			{
				int j;
				for(j=0;j<n;j++)
				{
					if(j!=temp && check[j]>0)
						break;
				}
				cout << char(j+97);
				check[j]--;
				temp = j;
			}
			cout << endl;
		}
		else
			cout << "-1" << endl;
	}
}
