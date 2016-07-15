/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 15 March 2015 11:38:24  IST
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

int sub[10];

void next(int max, int length) {

	int pos = length - 1;

	//find first digit that can be increased
	while(pos >= 0)
	{
		if(sub[pos] == max - (length - 1 - pos))
			pos--;

		else
			break;
	}

	sub[pos]++; //increase digit

	//update other digits
	for(int a = pos+1; a < length; a++)
		sub[a] = sub[a-1] + 1;

}

int main()
{
	string word;
	cin >> word; 

	int max = word.length() - 1; //max value

	int largest[10] = {'0','0','0','0','0','0','0','0','0','0'};

	for(int n=1; n <= max+1; n++)
	{
		for(int i = 0; i < n; i++)
		{
			sub[i] = i;
		}

		for(int a = 0; ; a++)
		{		
			if(word[sub[0]] == word[sub[n-1]])
			{
				for(int c=0; c < n; c++)
				{
					if(word[sub[c]] > word[largest[c]])
					{
						for(int k=0; k < n; k++)
							largest[k] = sub[k];

						break;
					}
					else if(word[sub[c]] < word[largest[c]])
						break;
				}
			}		

			if(sub[0] == max - (n - 1))
				break;
			else
				next(max, n); //maximum value and last position
		}	

	}	

	for(int j=0; j < max; j++)
		cout << word[largest[j]];

	cout << '\n';


	return 0;
}
