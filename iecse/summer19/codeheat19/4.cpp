/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define  ull unsigned long long int

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

ll modexp(ll a,ll b, ll mod){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}

ll modinv(ll a,ll mod){
	return modexp(a,mod-2,mod);
}

int main()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> arr(n);
	REP(i,n){
		cin >> arr[i];
		arr[i] %= k;
	}
	map<ll,ll> c;
	REP(i,k)
		c[i] = 0;
	REP(i,n)
		c[arr[i]]++;
	ll aux=0,ans=0;
	FOR(i,1,k){
		ll inv = modinv(i,k);
		if((inv!=i) && (inv<k))
			ans += max(c[inv],c[i]);
		else if(inv!=i)
			ans += c[i];
	}
	ans >>= 1;
	cout << ans + c[0] << endl;
	return 0;
}

