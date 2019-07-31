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
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
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

#define MOD 100000000

ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		b >>=1;
		a = (a*a)%MOD;
	}
	return ans;
}

ll fact(ll n){
	if(n<=1)
		return 1;
	return (n*fact(n-1))%MOD;
}

ll modmul(ll a,ll b){
	return (a*b)%MOD;
}

ll modadd(ll a,ll b){
	return (a+b)%MOD;
}

ll modsub(ll a,ll b){
	return (a-b+MOD)%MOD;
}

ll modinv(ll a){
	return modexp(a,MOD-2);
}

ll nCr(ll n,ll r){
	return modmul(fact(n),modinv(modmul(fact(n-r),fact(r))));
}

int main()
{
	fast_io;
	ll n1,n2,k1,k2;
	cin >> n1 >> n2 >> k1 >> k2;
	ll n = n1+n2;
	ll tot = fact(n);
	error(tot);
	ll p1 = modmul(modmul(n-k1,fact(k1+1)),nCr(n-k1-1,k2));
	error(p1);
	ll p2 = modmul(modmul(n-k2,fact(k2+1)),nCr(n-k2-1,k1));
	cout << tot - p1 - p2 << endl;
	return 0;
}

