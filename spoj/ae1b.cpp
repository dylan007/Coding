/*
 * =====================================================================================
 *
 *       Filename:  ae1b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 02 April 2015 11:14:15  IST
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
	int n,k,s;
	cin >> n >> k >> s;
	int sc[n];
	for(int i=0;i<n;i++)
		cin >> sc[i];
	sort(sc,sc+n);
	k *= s;
	int c=0,i=n-1;
	while(k>0)
	{
		c++;
		k-=sc[i];
		i--;
	}
	cout << c << endl;
}
