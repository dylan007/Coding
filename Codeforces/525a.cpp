/*
 * =====================================================================================
 *
 *       Filename:  525a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 10 May 2015 08:54:14  IST
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
	int l;
	cin >> l;
	string stream;
	cin >> stream;
	int count=0;
	int c[26];
	memset(c,0,4*26);
	l--;
	for(int i=0;i<2*l;i++)
	{
		if(i%2 == 0)
			c[stream[i]-'a']++;
		else
		{
			if(c[stream[i]-'A']==0)
				count++;
			else
				c[stream[i]-'A']--;
		}
	}
	cout << count << endl;
	return 0;
}
