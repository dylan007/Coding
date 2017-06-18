//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,k,x,y;
		cin >> n >> k;
		vector< vector< int > > vals;
		vector<int> sum(k,0);
		vector<int> temp;
		int min=0;
		for(int i=0;i<n;i++)
		{
			cin >> x;
			while(x--)
			{
				cin >> y;
				sum[y-1]++;
			}
		}
		for(int i=0;i<k;i++)
			min = min<sum[i]?sum[i]:min;
		cout << (min*(min-1))/2 << endl;
	}
	return 0;
}

