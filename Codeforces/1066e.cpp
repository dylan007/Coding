/*=======================
Author    : Shounak Dey
Filename  : 1066e.cpp
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

#define MOD 998244353

ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		a = (a * a)%MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	fast_io;
	ll l1,l2;
	cin >> l1 >> l2;
	string a,b;
	cin >> a >> b;
	ll ans=0;
	ll pos=max(0ll,l2-l1);
	ll curr=0;
	REP(i,pos)
		curr += b[i]=='1';
	ll x = 499122177;
	// error(x);
	ll start = max(0ll,l1-l2);
	// error(start);
	ll exp = l1-start;
	ll pow = 1;
	ll base = 2;
	while(exp){
		if(exp&1)
			pow = (pow * base)%MOD;
		base = (base*base)%MOD;
		exp >>= 1;
	}
	FOR(i,start,l1){
		pow = (pow * x)%MOD;
		curr += b[pos]=='1';
		ans = (ans + (a[i]=='1')*(curr * pow)%MOD)%MOD;
		pos++;
	}
	cout << ans << endl;
	return 0;
}