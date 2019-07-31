/*=======================
Author    : Shounak Dey
Filename  : 6.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

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
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		a -= c;
		b -= d;
		c = 0;
		d = 0;
		a = abs(a);
		b = abs(b);
		cout << max(a,b) << endl;
	}	
	return 0;
}