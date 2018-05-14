//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	int x;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int q;
	cin >> q;
	while(q--)
	{
		int y;
		cin >> y;
		cout << upper_bound(a.begin(),a.end(),y) - a.begin() << endl;
	}
	return 0;
}

