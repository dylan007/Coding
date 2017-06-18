//Shounak Dey
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define size(a) (int)(sizeof(a))
vector<int> flag(1000000,0);

void sieve()
{
	flag[1] = 1;
	for(int i=2;i<=1000000;i++)
	{
		if(!flag[i])
		{
			for(int j=2*i;j<=1000000;j+=i)
				flag[j] = 1;
		}
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	sieve();
	while(T--)
	{
		ll x;
		cin >> x;
		ll t = sqrt(x);
		if(!flag[t] && (x==(t*t)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

