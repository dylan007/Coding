/*
 * =====================================================================================
 *
 *       Filename:  507b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 10 July 2016 09:54:21  IST
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

double dist(double x1,double x2, double y1,double y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main()
{
	double r,x1,x2,y1,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	cout << int(ceil(dist(x1,x2,y1,y2)/(2*r))) << endl;
	return 0;
}
