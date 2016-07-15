/*
 * =====================================================================================
 *
 *       Filename:  decjoe.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 15 March 2015 09:59:35  IST
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

int lps(string str)
{
	int n = str.length();
	int i, j, cl;
	int L[n][n];  // Create a table to store results of subproblems
	for(i = 0; i < n; i++)
		L[i][i] = 1;

	for (cl=2; cl<=n; cl++)
	{
		for (i=0; i<n-cl+1; i++)
		{
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
				L[i][j] = 2;
			else if (str[i] == str[j])
				L[i][j] = L[i+1][j-1] + 2;
			else
				L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}
	return L[0][n-1];
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string y,s;
		cin >> y >> s;
		cout << y << endl << s << endl;
		int max = lps(s);
		for(int i=0;i<(s.length()-max);i++)
		{
			string temp;
			temp = s.substr(i,max);
			cout << temp << endl;
			if(temp == string(temp.rbegin(),temp.rend()))
				cout << temp;
		}
	}
	return 0;
}
