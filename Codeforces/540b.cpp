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

int main()
{
	int n,k,x,p,y;
	cin >> n >> k >> p >> x >> y;
	vector<int> orig;
	int sum=0;
	int cless=0;
	for(int i=0;i<k;i++)
	{
		int a;
		cin >> a;
		orig.push_back(a);
		cless += (a<y);
		sum += a;
	}
	sort(orig.begin(),orig.end());
	if(cless > (n-1)/2) 
	{
		cout << "-1\n";
		return 0;
	}
	if(sum+(n-k) > x)
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << cless << endl;
	
	return 0;
}
