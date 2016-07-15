/*
 * =====================================================================================
 *
 *       Filename:  anarco8e.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 10 May 2015 05:54:57  IST
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

long long int fact(int x)
{
	if(x==0)
		return 1;
	return x*fact(x-1);
}

int main()
{
	int x,y;
	cin >> x >> y;
	while(x!=y && x!=-1)
	{
		int ans;
		ans = ((fact(x+y)))/(fact(x)*fact(y));
		if(ans == (x+y))
			cout << x << "+" << y << "=" << ans << endl;
		else
			cout << x << "+" << y << "!=" << ans << endl;
		cin >> x >> y;
	}
}
