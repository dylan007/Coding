/*=======================
Author    : Shounak Dey
Filename  : 9.cpp
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

int main()
{
	ll m;
	cin >> m;
	ll arr[m][m];
	vector<vector<ll>> rows(m,vector<ll>(m,0)),cols(m,vector<ll>(m,0));
	REP(i,m){
		REP(j,m){
			cin >> arr[i][j];
			rows[i][j] = arr[i][j];
			cols[j][i] = arr[i][j];
		}
	}	
	REP(i,m){
		SORTV(rows[i]);
		SORTV(cols[i]);
	}
	vector<ll> r(m,INT_MAX),c(m,0);
	REP(i,m){
		REP(j,m){
			c[j] = max(c[j],arr[i][j]);
			r[i] = min(r[i],arr[i][j]);
		}
	}
	ll R=0,C=INT_MAX;
	REP(i,m){
		R = max(R,r[i]);
		C = min(C,c[i]);
	}
	if(R==C)
		cout << 0 << endl;
	else{
		ll ans = INT_MAX;
		FOR(tmp,R,C+1){
			ll c1=INT_MAX,c2=INT_MAX;
			REP(i,m){
				ll l = 0;
				// REP(j,m)
				// 	l += (arr[i][j]<tmp);
				auto it = lower_bound(rows[i].begin(),rows[i].end(),tmp);
				if(it==rows[i].end())
					l = m;
				else
					l = it-rows[i].begin();
				c1 = min(l,c1);
			}
			REP(j,m){
				ll l=0;
				// REP(i,m)
				// 	l += (arr[i][j]>tmp);
				auto it = upper_bound(cols[j].begin(),cols[j].end(),tmp);
				if(it==cols[j].end())
					l = 0;
				else
					l = m - (it-cols[j].begin());
				c2 = min(l,c2);
			}
			ans = min(ans,c1+c2);
		}
		cout << ans << endl;
	}
	return 0;
}