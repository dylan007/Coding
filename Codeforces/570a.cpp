/*
 * =====================================================================================
 *
 *       Filename:  570a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 03 July 2016 02:06:03  IST
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
	int n,m;
	cin >> n >> m;
	vector<int> score;
	for(int i=0;i<n;i++)
		score.push_back(0);
	int winner=0,win_score=0;
	for(int i=0;i<m;i++)
	{
		int x, max=0,ind=0;
		for(int j=0;j<n;j++)
		{
			cin >> x;
			if(max < x)
			{
				max = x;
				ind = j;
			}
		}
		score[ind]++;
	}
	for(int i=0;i<n;i++)
	{
		if(win_score < score[i])
		{
			win_score = score[i];
			winner = i;
		}
	}
	//cout << win_score <<  " " << winner << endl;
	cout << winner+1 << endl;
	return 0;
}
