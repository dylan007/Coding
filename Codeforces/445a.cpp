#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int i,j;
	char c;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin >> c;
			if(c=='-')
				cout << c;
			else if(c=='.')
			{
				if((i+j)%2 == 0)
					cout << "B";
				else
					cout << "W";
			}
		}
		cout << endl;
	}
	return 0;
}
