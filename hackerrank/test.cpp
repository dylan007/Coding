/*
 * =====================================================================================
 *
 *       Filename:  TEST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 15 March 2015 11:40:55  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>

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

	int max = 7; //max value


	for(int n=1; n <= max+1; n++)
	{

		cout << n << "\n----\n";

		for(int i = 0; i < n; i++)
		{
			sub[i] = i;
		}

		for(int a = 0; ; a++)
		{				
			for(int b=0; b < n; b++)
				cout << word[sub[b]];

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

