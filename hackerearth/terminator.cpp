/*
 * =====================================================================================
 *
 *       Filename:  terminator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 23 July 2015 09:17:47  IST
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
		string inp;
		cin >> inp;
		int flag=0;
		int l = inp.length();
		string t;
		for(int i=0;i<l;i++)
		{
			if(i==0)
				string temp;
			else if(inp[i]=='*' && i!=0)
			{
				if(flag=1)
				{
					for(int j=0;j<temp.length();j++)
					{
						if(inp[i]!='o')
							cout << temp[i];
					}
				}
				else
					cout << temp;
				string temp;
				flag=0;
			}
			temp += inp[i];
			t = temp;
			if(inp[i] == 'x')
				flag=1;
		}
		if(flag==1)
		{
			for(int i=0;i<t.length();i++)
			{
				if(inp[i]!='o')
					cout << temp[i];
			}
		}
		else
			cout << temp;
		cout << endl;
	}
	return 0;
}
