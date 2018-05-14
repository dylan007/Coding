#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int full=0;
	for(int i=0;i<n;i++)
	{
		if(i%2 == 0)
		{
			for(int j=0;j<m;j++)
				cout << "#";
			cout << endl;
		}
		else
		{
			if(full%2 == 1)
			{
				cout << "#";
				for(int j=0;j<(m-1);j++)
					cout << ".";
			}
			else
			{
				for(int j=0;j<(m-1);j++)
					cout << ".";
				cout << "#";
			}
			cout << endl;
			full++;
		}
	}
	return 0;
}
