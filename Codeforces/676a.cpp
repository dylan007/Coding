/*
 * =====================================================================================
 *
 *       Filename:  676a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Tuesday 12 July 2016 10:29:00  IST
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
	int x,m=INT_MAX,M=INT_MIN,min_ind,max_ind;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x>M)
		{
			M = x;
			max_ind = i;
		}
		if(x<m)
		{
			m = x;
			min_ind = i;
		}
	}
	//cout << M << " " << m << " " << max_ind << " " << min_ind << endl;
	int ans=0;
	if(max_ind>min_ind)
	{
		ans += (max_ind-min_ind);
		max_ind = n-1-max_ind;
		ans += max(max_ind,min_ind);
	}
	else
	{
		ans += (min_ind-max_ind);
		//cout << ans << " ";
		min_ind = n-1-min_ind;
		ans += max(max_ind,min_ind);
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
