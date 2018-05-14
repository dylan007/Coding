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

int cmp(const void *x, const void *y)
{
	  double xx = *(double*)x, yy = *(double*)y;
	    if (xx < yy) return -1;
	      if (xx > yy) return  1;
	        return 0;
}

int main()
{
	int n;
	double w;
	cin >> n >> w;
	n*=2;
	int cups[n];
	for(int i=0;i<n;i++)
		cin >> cups[i];
	sort(cups,cups+n);
	printf("%.6lf\n",min(min(cups[0]*3.0,cups[n/2]*1.5)*n/2,double(w)));
	return 0;
}
