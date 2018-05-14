/*
 * =====================================================================================
 *
 *       Filename:  decjoe2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 15 March 2015 10:27:02  IST
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
	for (i = 0; i < n; i++)
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

int sub[100000];

void next(int max, int length) 
{
	int pos = length - 1;
	while(pos >= 0)
	{
		if(sub[pos] == max - (length - 1 - pos))
			pos--;
		else
			break;
	}
	sub[pos]++; //increase digit
	for(int a = pos+1; a < length; a++)
		sub[a] = sub[a-1] + 1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string y,s;
		cin >> y >> s;
		int n = lps(s);
		int max = s.length()-1;
		cout << n;
		for(int i = 0; i < n; i++)
			sub[i] = i;
		for(int a = 0; ; a++)
		{				
			for(int b=0; b < max+1; b++)
				cout << s[sub[b]];

			cout << '\n';

			if(sub[0] == max - (n - 1))
				break;

			else
				next(max, n); //maximum value and last position
		}	

		cout << '\n';
	}
	return 0;
}
