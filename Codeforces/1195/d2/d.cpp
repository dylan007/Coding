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

#define MOD 998244353

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<string> num(n);
	vector<ll> mul(20,1);
	FOR(i,1,20)
		mul[i] = (mul[i-1]*10)%MOD;
	REP(i,n)
		cin >> num[i];
	vector<ll> nl(20,0);
	REP(i,n)
		nl[num[i].length()]++;
	FOR(i,1,20)
		nl[i] += nl[i-1];
	ll ans=0;
	REP(i,n){
		string a = num[i];
		ll cl = 1;
		for(ll j=a.length()-1;j>=0;j--){
			ll x = a[j]-'0';
			ll c = n - nl[cl-1];
			ans = (ans + (x * c * mul[2 * (cl-1)])%MOD)%MOD;
			ans = (ans + (x * c * mul[2 * (cl-1) + 1])%MOD)%MOD;
			c = 0;
			FOR(i,1,cl){
				c = 2*(nl[i]-nl[i-1]);
				ans = (ans + (x * c * mul[cl+i-1])%MOD)%MOD;
			}
			cl++;
		}
	}
	cout << ans << endl;
	return 0;
}

