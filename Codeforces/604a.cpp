/*
 * =====================================================================================
 *
 *       Filename:  604a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Monday 07 December 2015 08:37:38  IST
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
	double m[5];
	double w[5];
	double hs,hf;
	for(int i=0;i<5;i++)
		cin >> m[i];
	for(int i=0;i<5;i++)
		cin >> w[i];
	cin >> hs >> hf;
	double x=500;
	double sum = 0;
	for(int i=0;i<5;i++)
	{
		sum += max(0.3*(i+1)*500,(1-m[i]/250)*(i+1)*x-50*w[i]);
	}
	cout << sum+hs*(100.00)-hf*(50.00) << endl;
	return 0;
}
