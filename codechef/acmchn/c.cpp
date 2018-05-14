/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 28 October 2015 05:58:48  IST
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

int binsearch(vector<int> a, int x,int start,int end)
{
	int mid;
	while(start<end)
	{
		mid = (start+end)/2;
		if(a[mid] > x)
			end = mid;
		else
			start = mid+1;
	}
	return mid;
}

int binarySearch(vector<int> arr, int l, int r, int x)
{
	if (r>=l)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid-1, x);
		return binarySearch(arr, mid+1, r, x);
	}
	return -1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int p;
		p = n;
		int x;

		vector < int > in;
		for(int i=0;i<n;i++)
		{
			cin >> x;
			in.push_back(x);
		}
		vector < int > fin;
		while(n>0)
		{
			int a;
			if(in[0]>in[n-1])
				a = 1;
			else
				a = 0;
			if(a == 0)
			{
				a = in[0];
				in.erase(in.begin());
			}
			else
			{
				a = in[n-1];
				in.erase(in.end());
			}
			if(fin.length() > 0)
			{
				x = binsearch(fin,a,0,fin.length());
				if(x > (fin.length())/2)
					fin.push_back(a);
				else
					fin.insert(fin.begin(),a);
			}
			else
				fin.push_back(a);
			n--;
		}
		for(int i=0;i<fin.length();i++)
			cout << fin[i] << " " << endl;
	}
	return 0;
}
