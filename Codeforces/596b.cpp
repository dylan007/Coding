/*
 * =====================================================================================
 *
 *       Filename:  596b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 14 July 2016 10:22:30  IST
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

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll x,y;
	ll score=0;
	cin >> x;
	score = abs(x);
	for(int i=0;i<(n-1);i++)
	{
		y = x;
		cin >> x;
		score += max(y,x)-min(y,x);
	}
	cout << score << endl;
	return 0;
}
