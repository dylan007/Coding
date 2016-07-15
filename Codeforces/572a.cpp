/*
 * =====================================================================================
 *
 *       Filename:  572a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 08 July 2016 06:49:33  IST
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
	int n1,n2;
	cin >> n1 >> n2;
	int k,m;
	cin >> k >> m;
	int a1[n1],a2[n2];
	for(int i=0;i<n1;i++)
		cin >> a1[i];
	for(int i=0;i<n2;i++)
		cin >> a2[i];
	k--;
	m = n2-m;
	if(a1[k]<a2[m])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
