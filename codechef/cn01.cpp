#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	cin >> x;
	char seq[1010];
	cin >> seq;
	int i,len;
	len = strlen(seq);
	for(i=0;i<len;i++)
	{
		if(seq[i]=='L')
		{
			x += (x%2);
			x/=2;
		}
		else
			x = 2*x+11;
	}
	cout << x << endl;
	return 0;
}
