/*
 * =====================================================================================
 *
 *       Filename:  ankparen.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 21 June 2015 10:01:22  IST
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

vector<string> strvector;

void allsubstrings(string str,int st_index,int end_index)
{
	string st1,st2;
	vector<string> tempvector;
	vector<string>::iterator it;
	if(st_index == end_index)
	{
		st1.push_back(str[st_index]);
		strvector.push_back(st1);
	}
	else
	{
		allsubstrings(str,st_index+1,end_index);
		for(it = strvector.begin(); it != strvector.end(); ++it)
		{
			st2 = *it;
			st2 += str[st_index];
			tempvector.push_back(st2);
			st2.clear();
		}
		st1.push_back(str[st_index]);
		tempvector.push_back(st1);
		strvector.insert( strvector.end(), tempvector.begin(), tempvector.end() );
	}
} 

int main()
{
	vector<string> ans;
	string S1 = "(()";
	allsubstrings(S1,0,S1.length()-1);
	for(int j = 0;j<strvector.size();j++)
		cout << strvector[j] << endl;
	return 0;
}
