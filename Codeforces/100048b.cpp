/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 21 May 2015 03:51:34  IST
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

long long int fact(long long int x)
{
	if(x==0)
		return 1;
	if(x==1)
		return 1;
	else
		return x*fact(x-1);
}

int main()
{
	long long int n;
	cin >> n;
	while(cin >> n)
	{
		if(n==0)
			cout << "1" << endl;
		else if(n==1)
			cout << "A+B" << endl;
		else
		{
			long long int i=n;
			while(i>=0)
			{
				long long int ans;
				ans = fact(n)/(fact(i)*fact(n-i));
				if(ans>1)
					cout << ans << "x";
				if(i>0)
				{
					cout << "A";
					if(i>1)
						cout << "^" << i;
				}
				if(n-i > 0)
				{
					cout << "B";
					if((n-i)>1)
						cout << "^" << (n-i);
				}
				i--;
				if(i>=0)
					cout << "+";
				else
					cout << endl;
			}
		}
	}
	return 0;
}
