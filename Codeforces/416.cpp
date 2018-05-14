#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<limits.h>

using namespace std;

int main()
{
	int r=INT_MIN,l=INT_MAX;
	int T;
	cin >> T;
	char inp[10];
	while(T--)
	{
		scanf("%[\n]",inp);
		getchar();
		printf("%s\n",inp);
		if(inp[strlen(inp)-1]=='Y')
		{
			if(inp[0]=='>')
			{
				if(inp[1]=='=')
				{
					if(l>(inp[3]-'0'))
						l = inp[3]-'0';
				}
				else
					if(l>(inp[2]-'1'))
						l = inp[2]-'1';
			}
			if(inp[0]=='<')
			{
				if(inp[1]=='=')
				{
					if(r<(inp[3]-'0'))
						r = inp[3]-'0';
				}
				else
					if(r<(inp[2]-'1'))
						r = inp[2]-'1';
			}
		}
	}
	cout << l << r << endl;
	if(l>r)
		cout << "Impossible" << endl;
	else
		cout << l << endl;
	return 0;
}
