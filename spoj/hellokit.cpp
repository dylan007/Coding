/*
 * =====================================================================================
 *
 *       Filename:  hellokit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 April 2015 06:06:22  IST
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
	string inp;
	int len;
	cin >> inp;
	cin >> len;
	int length;
	length = inp.length()-1;
	while(inp[0]!='.')
	{
		string con=inp;
		for(int i=1;i<len;i++)
			con = con+inp;
		string temp = con;
		cout << con << endl;
		while(length--)
		{
			rotate(temp.begin(),temp.begin()+1,temp.end());
			cout << temp << endl;
		}
		cin >> inp;
		if(inp[0]=='.')
			break;
		cin >> len;
		length = inp.length()-1;
	}
	return 0;
}
