/*
 * =====================================================================================
 *
 *       Filename:  proposals.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 23 July 2015 09:03:23  IST
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
		int l = inp.length();
		int check[26];
		memset(check,0,sizeof(check));
		int max=0;
		for(int i=0;i<l;i++)
		{
			int t;
			t = int(inp[i])-int('a');
			check[t]++;
			max = max>check[t]?max:check[t];
		}
		for(int i=0;i<26;i++)
		{
			if(check[i]==max)
			{
				char c;
				c = char(i+int('a'));
				cout << c;
			}
		}
		cout << " " << max;
		cout << endl;
	}
	return 0;
}
