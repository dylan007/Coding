/*
 * =====================================================================================
 *
 *       Filename:  name2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 17 May 2015 09:24:03  IST
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

int substring(string inp1,string inp2,int m,int n)
{
	if(m>n)
		return 0;
	int j=0;
	int i;
	for(i=0;i<m;i++)
	{
		while(j<n)
		{
			if(inp2[j] == inp1[i])
				break;
			j++;
		}
		if(j>n)
			return 0;
		i++;
		j++;
	}
	return 1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string inp1,inp2;
		cin >> inp1 >> inp2;
		if(substring(inp1,inp2,inp1.length(),inp2.length())==1 || substring(inp2,inp1,inp2.length(),inp1.length())==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
