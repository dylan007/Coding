/*
 * =====================================================================================
 *
 *       Filename:  611a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 03:31:09  IST
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
	string a;
	std::getline(cin,a);
//	cout << a << endl;
	int l = a.length();
//	cout << l << endl;
	if(a[l-1] == 'k')
	{
		int num = int(a[0])-int('0');
		if(num==5 || num==6)
			cout << "53" << endl;
		else
			cout << "52" << endl;
	}
	else
	{
		int num=0;
		if(l==11)
			num = 10*(int(a[0])-int('0'))+int(a[1])-int('0');
		else
			num = int(a[0])-int('0');
		if(num==31)
			cout << "7" << endl;
		else if(num<=30 && num>29)
			cout << "11" << endl;
		else
			cout << "12" << endl;
	}
	return 0;
}
