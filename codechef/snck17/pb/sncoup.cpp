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
		ll n;
		cin >> n;
		string a,b;
		cin >> a >> b;
		//cout << a << endl << b << endl;
		vector<ll> h(a.length(),0);
		ll count=0;
		for(int i=0;i<a.length();i++)
			count |= ((a[i]=='*') && (b[i]=='*'));
		//cout << count << endl;
		for(int i=0;i<a.length();i++)
			count += (a[i]=='*' || b[i]=='*');
		cout << max(ll(0),count-1) << endl;
	}
	return 0;
}

