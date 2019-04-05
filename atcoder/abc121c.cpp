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

int main()
{
	fast_io;
	ll n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> arr(n,pair<ll,ll>());
	REP(i,n)
		cin >> arr[i].F >> arr[i].S;
	sort(arr.begin(),arr.end(),[](const pair<ll,ll> &a, const pair<ll,ll> &b){
		double r1,r2;
		r1 = (double)a.S / (double)a.F;
		r2 = (double)b.S / (double)b.F;
		return r1 < r2;
	});
	for(auto it: arr)
		cout << it.F << " " << it.S << endl;
	ll ans=0,curr=m;
	REP(i,n){
		ll q = min(curr,arr[i].S);
		ans += q * arr[i].F;
		error(curr,q,ans);
		curr -= q;
	}
	cout << ans << endl;
	return 0;
}
