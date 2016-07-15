/*
 * =====================================================================================
 *
 *       Filename:  perfect-hiring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 20 June 2015 09:45:39  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	long long int n,p,x;
	cin >> n >> p >> x;
	long long int max=0;
	long long int y;
	int index;
	for(int i=0;i<n;i++)
	{
		cin >> y;
		if(max < (p*y))
		{
			index = i+1;
			max = p*y;
		}
		p -= x;
	}
	cout << index << endl;
	return 0;
}

