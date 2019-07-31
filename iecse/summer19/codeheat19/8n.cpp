/*=======================
Author    : Shounak Dey
Filename  : 8n.cpp
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

vector<pair<ll,ll>> val = vector<pair<ll,ll>>(1000,pair<ll,ll>());
ll ans = LONG_MAX;
ll n,k;

void calc(ll s,ll r,ll dist, ll pos, ll move){
	ll start = val[pos].F;
	ll end = val[pos].S;
	if(move==0){
		if(s==-1){
			s = end;
			dist += abs(start-end);
		}
		else{
			dist += abs(s-start) + abs(start-end);
			s = end;
		}
	}
	else{
		if(r==-1){
			r = end;
			dist += abs(start-end);
		}
		else{
			dist += abs(r-start) + abs(start-end);
			r = end;
		}
	}
	if(pos==(k-1)){
		ans = min(ans,dist);
		return;
	}
	calc(s,r,dist,pos+1,0);
	calc(s,r,dist,pos+1,1);
	return;
}

int main()
{
	TEST{
		cin >> n >> k;
		val = vector<pair<ll,ll>>(1000,{0,0});
		REP(i,k)
			cin >> val[i].F >> val[i].S;
		calc(-1,-1,0,0,0);
		calc(-1,-1,0,0,1);
		cout << ans << endl;
		ans = LONG_MAX;
	}
	return 0;
}