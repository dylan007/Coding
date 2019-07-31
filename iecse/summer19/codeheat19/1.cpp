/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

#define PB push_back
#define MK make_pair
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)

int main()
{
	TEST{
		ll n;
		cin >> n;
		ll a=0,b=0;
		ll x;
		REP(i,n){
			cin >> x;
			a += x;
		}
		REP(i,n){
			cin >> x;
			b += x;
		}
		if(a>b)
			cout << "Kashites" << endl;
		else if(a<b)
			cout << "Parshites" << endl;
		else
			cout << "Global Warming" << endl;
	}
	return 0;
}

