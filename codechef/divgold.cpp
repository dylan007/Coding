/*
 * =====================================================================================
 *
 *       Filename:  divgold.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 22 March 2015 10:03:40  IST
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
		int len;
		cin >> len;
		string a;
		cin >> a;
		int i,j;
		int f=0;
		string ans;
		for(i=0;i<(len-1);i++)
		{
			int min=a[i]-'A',index=i;
			char temp;
			for(j=i+1;j<(len);j++)
			{
				if(min >= a[j]-'A')
				{
					min = a[j]-'A';
					index=j;
				}
			}
			if(index!=i)
			{
				ans.append(a.begin()+0,a.begin()+i);
				ans.append(a.begin()+index,a.begin()+index+1);
				ans.append(a.begin()+i,a.begin()+index);
				ans.append(a.begin()+index+1,a.begin()+len);
				f=1;
				break;
			}
		}
		if(f==1)
			cout << ans << endl;
		else
			cout << a << endl;
	}
	return 0;
}
