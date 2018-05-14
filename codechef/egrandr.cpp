/*
 * =====================================================================================
 *
 *       Filename:  egrandr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 11 July 2016 02:33:14  IST
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
		double n;
		cin >> n;
		double sum=0;
		int top=0,fail=0;
		double x;
		for(int i=0;i<int(n);i++)
		{
			cin >> x;
			sum += x;
			if(x==2) 
				fail=1;
			else if(x==5) 
				top=1;
		}
		//cout << fail << " " << top << endl;
		//cout << sum << " " << sum/5.0 << endl;
		if(!fail && top && (sum/5.0 >= 4.0))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
