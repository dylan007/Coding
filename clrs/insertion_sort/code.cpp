/*
 * =====================================================================================
 *
 *       Filename:  code.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 10 June 2016 10:03:44  IST
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

int* insertion_sort(int *a,int n)
{
	int *c = a;
	return c;
}

int main()
{
	int n;
	cin >> n;
	int a = new int[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int *c = insertion_sort(a,n);
	for(int i=0;i<n;i++)
		cout << c[i] << endl;
	return 0;
}
