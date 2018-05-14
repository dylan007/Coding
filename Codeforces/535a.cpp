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

string ans[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string ans2[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main()
{
	int n;
	cin >> n;
	if(n>=0 && n<20)
		cout << ans[n] << endl;
	else
	{
		cout << ans2[n/10-2];
		if(n%10 != 0)
			cout << "-" << ans[n%10];
		cout << endl;
	}
	return 0;
}
