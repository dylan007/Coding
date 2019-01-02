/*=======================
Author    : Shounak Dey
Filename  : readcost.cpp
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

int main()
{
	//Value for ith person will be floor((x + (i-1)*n)/m). The value of floors change in intervals of m. So count values in each range km to (k+1)m and add the corresponding values.
	fast_io;
	ll n,m,x;
	cin >> n >> m >> x;
	auto check = [](ll n,ll m,ll x){
		return !(n==0 && m==0 && x==0);
	};
	while(check(n,m,x)){
		ll ans=0;
		ll l=0,r=m-1;
		ll maxr = x + (m-1)*n;
		ll iter = (maxr/m) + 10;
		ll curr = x;
		while(iter--){
			if(r > maxr)
				r = maxr;
			if(curr > r){
				l += m;
				r += m;
				continue;
			}
			ll k = (r-curr)/n + 1;
			ans += k*(l/m);
			curr += k*n;
			l += m;
			r += m;
			if(l>maxr)
				break;
		}
		cout << ans << endl;
		cin >> n >> m >> x;
	}
	return 0;
}