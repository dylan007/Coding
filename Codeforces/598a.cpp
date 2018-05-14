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
	int T;
	cin >> T;
	while(T--)
	{
		ll n;
		cin >> n;
		ll x = ll(log2(n));
		cout << (n*(n+1)/2) - 2*((1<<(x+1))-1) << endl;
	}
	return 0;
}

