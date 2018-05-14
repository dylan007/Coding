/*
 * =====================================================================================
 *
 *       Filename:  mirrored.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 April 2015 06:57:31  IST
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
	cout << "Ready" << endl;
	while(1)
	{
		cin >> inp;
		cout << inp << endl;
		if(isspace(inp[0]) && isspace(inp[1]))
			return 0;
		if(((inp[0]=='d' && inp[1]=='b')||(inp[0]=='b' && inp[1]=='d')) || ((inp[0]=='q' && inp[1]=='p')||(inp[0]=='p' && inp[1]=='q')) || ((inp[0]==inp[1] && inp[0]=='H'))|| ((inp[0]==inp[1] && inp[0]=='I'))|| ((inp[0]==inp[1] && inp[0]=='M'))|| ((inp[0]==inp[1] && inp[0]=='O'))|| ((inp[0]==inp[1] && inp[0]=='T'))|| ((inp[0]==inp[1] && inp[0]=='U'))|| ((inp[0]==inp[1] && inp[0]=='V'))|| ((inp[0]==inp[1] && inp[0]=='W'))|| ((inp[0]==inp[1] && inp[0]=='X'))|| ((inp[0]==inp[1] && inp[0]=='i'))|| ((inp[0]==inp[1] && inp[0]=='m'))|| ((inp[0]==inp[1] && inp[0]=='o'))|| ((inp[0]==inp[1] && inp[0]=='v'))|| ((inp[0]==inp[1] && inp[0]=='w'))|| ((inp[0]==inp[1] && inp[0]=='x')))
			cout << "Mirrored pair" << endl;
		else
			cout << "Ordinary pair" << endl;
	}
	return 0;
}
