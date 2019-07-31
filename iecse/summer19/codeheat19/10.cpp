/*=======================
Author    : Shounak Dey
Filename  : 10.cpp
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
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits

#define MOD 1000000007

int main()
{
	// FOR(i,1,30){
		ll f[] = {2,3,5,6,8,11,16};
		ll diff[] = {1,3,6,11,16,24,35,51};
		ll x;
		cin >> x;	
		// x = i;
		if(x<=7)
			cout << f[x-1] << endl;
		else{
			x-=7;
			// cout << "X: " << x << endl; 
			ll ans = 16;
			ans = (ans + ((51 * ((x/8)-((x%8)==0)))%MOD))%MOD;
			x--;
			cout << (ans + diff[x%8])%MOD << endl;
		}
	// }
	return 0;
}