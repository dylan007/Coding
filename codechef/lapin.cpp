/*
 * =====================================================================================
 *
 *       Filename:  lapin.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 08 June 2016 04:11:24  IST
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
		string s;
		cin >> s;
		int len;
		len = s.size();
		string s1,s2;
		s1 = s.substr(0,len/2);
		s2 = s.substr(len/2+(len%2),len/2);
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		//cout << s1 << " " << s2 << endl;
		if(s1.compare(s2) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
