/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 07 October 2015 08:59:07  IST
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
		int count=0,n;
		cin >> n;
		vector <int> a;
		for(int i=1;i<=n;i+=2)
			a.push_back(i);
		int i=0;
		n = n/2;
		while(a.size()>1)
		{
			cout << a[i] << " " << n << " " << i << endl;
			cout << a[(i+1)%n] << endl;
			a.erase(a.begin()+(i+1)%n);
			n--;
			i = (i+1)%n;
		}
		cout << a[0] << endl;
	}
	return 0;
}
