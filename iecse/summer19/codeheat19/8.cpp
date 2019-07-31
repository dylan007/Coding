/*=======================
Author    : Shounak Dey
Filename  : 8.cpp
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

typedef struct node{
	ll s,r,dist;
}state;

int main()
{
	TEST{
		ll n,k;
		cin >> n >> k;
		ll ans=0;
		state s,r;
		s.s = s.r = -1;
		s.dist = 0;
		r.s = r.r = -1;
		r.dist = 0;
		while(k--){
			ll start,end;
			cin >> start >> end;
			
			// state s;
			if(s.s == -1){
				s.s = end;
				s.dist += abs(end-start);
			}
			else{
				ll dr,ds;
				ds = abs(s.s - start);
				dr = abs(s.r - start);
				if(ds > dr){
					s.dist += abs(s.s - start) + abs(end-start);
					s.s = end;
			}

			// state r;
			if(r.r == -1){
				r.r = end;
				r.dist += abs(end-start);
			}
			else{
				r.dist += abs(r.r - start) + abs(end-start);
				r.r = end;
			}
		}
		cout << min(s.dist,r.dist);
	}
	return 0;
}