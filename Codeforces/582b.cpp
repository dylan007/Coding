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
	int n,x;
	cin >> n;
	vector< pair <int,int> > a;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		pair <int,int> t;
		t.first = x;
		t.second = i;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	/*for(int i=0;i<n;i++)
	{
		cout << a[i].first << " " << a[i].second << endl;
	}*/
	int state = 1;
	int count=0;
	int temp=0;
	for(int i=0;i<n;i++)
	{
		cout << state << " " << a[i].second << " " << temp << endl;
		if(state==1)
		{
			if(a[i].second<temp)
			{
				state = -1;
				count++;
			}
			temp = a[i].second;
		}
		else if(state == -1)
		{
			if(a[i].second>temp)
			{
				state = 1;
				count++;
			}
			temp = a[i].second;
		}
	}
	cout << count << endl;
	return 0;
}
