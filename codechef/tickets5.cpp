/*
 * =====================================================================================
 *
 *       Filename:  tickets5.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 15 May 2015 09:01:20  IST
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
		int check[26];
		memset(check,0,4*26);
		int count=1;
		check[inp[0]-'A']++;
		char c = inp[0];
		int flag=0;
		for(int i=1;i<inp.length();i++)
		{
			if(check[inp[i]-'A']==0)
			{
				count++;
				check[inp[i]-'A']++;
			}
			if(count>2)
				break;
			if(c==inp[i])
			{
				flag=1;
				break;
			}
			else	
				c=inp[i];
		}
		//cout << count << " " << flag << endl;
		if(count>2 || flag==1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
