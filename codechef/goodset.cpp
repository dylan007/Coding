//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define push_back PB
#define make_pair MK
#define size(a) (int)(sizeof(a))

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int x=0;
		for(int i=0;i<n;i++)
		{
			if(i%2 == 0)
				cout << 10*x+1 << " ";
			else
			{
				cout << 10*x+9 << " ";
				x += 1;
			}
		}
		cout << endl;
	}
	return 0;
}

