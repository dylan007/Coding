#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n >>x;
		int y;
		int count=0;
		while(n--)
		{
			cin >> y;
			count += (y>=x);
		}
		cout << count << endl;
	}
	return 0;
}
