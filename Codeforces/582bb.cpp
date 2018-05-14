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
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[n];
	int count=0;
	int ans=0;
	int state = 1;
	int i=0;
	while(count <= (n-1))
	{
		if(state == 1)
		{
			int temp;
			while(i<n)
			{
				temp = 0;
				temp += a[i]==count;
				count += temp;
				i++;
			}
			ans += (count<=n);
			state = -1;
		}
		else if(state == -1)
		{
			int temp;
			while(i>0)
			{
				temp=0;
				temp += (a[i]==count);
				count += temp;
				i--;
			}
			ans += (count<=n);
			state = 1;
		}
		cout << count << endl;
	}
	cout << ans << endl;
	return 0;
}
