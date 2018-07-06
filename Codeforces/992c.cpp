/*=======================
Author    : Shounak Dey
Filename  : 992c.cpp
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
#define popc(a) __ builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

#define MOD 1000000007

ll modexp(ll x,ll e){
	ll ans =1;
	while(e>0){
		if(e&1)
			ans = (ans * x)%MOD;
		x = (x*x)%MOD;
		e >>= 1;
	}
	return ans;
}

ll modinv(ll x){
	return modexp(x,MOD-2);
}

int main()
{
	ll x,k;
	cin >> x >> k;
	if(k==0)
		cout << 2*x << endl;
	else if(x==0)
		cout << 0 << endl;
	else{
		// cout << (((modexp(2,k) * modexp(2,k))%MOD) * (x%MOD) )%MOD << endl;
		// cout << ((modexp(2,k-1)) * (modexp(2,k)-1))%MOD << endl;
		ll num = ((modexp(2,k+1) * x)%MOD - (modexp(2,k)-1))%MOD;
		// cout << num << endl;
		cout << num << endl; 
	}
	return 0;
}