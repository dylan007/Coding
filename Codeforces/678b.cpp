/*
 * =====================================================================================
 *
 *       Filename:  678b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 13 July 2016 10:30:40  IST
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

int check(int y)
{
	if(y%400 == 0)
		return 1;
	if((y%4 == 0)&&(y%100 != 0))
		return 1;
	return 0;

}

int main()
{
	int n;
	cin >> n;
	int x = n;
	int days=0;
	do {
		days++;
		if(check(x))
			days++;
		x++;
		days %= 7;
	}while(days || check(x)!=check(n));
	cout << x << endl;
	return 0;
}
