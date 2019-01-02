/*=======================
Author    : Shounak Dey
Filename  : 1091c.cpp
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
	fast_io;
	ll x;
	cin >> x;
	auto calc = [](ll x,ll k){
		ll ans=0;
		ll l = 1;
		ll n = ((x-1)/k) + 1;
		ll r = (n-1)*k + 1;
		ans += ((l+r)*(n))/2;
		l = r+k-x;
		while(l!=1){
			n = ((x-l)/k) + 1;
			r = (n-1)*k + l;
			ans += ((l+r)*(n))/2;
			l = r+k-x;
		}
		return ans;
	};
	set<ll> val;
	val.insert(calc(x,1));
	val.insert(1);
	ll curr = 2;
	while(curr*curr <= x){
		if((x%curr)==0){
			// error(curr);
			val.insert(calc(x,curr));
			val.insert(calc(x,x/curr));
		}
		curr++;
	}
	for(auto it: val)
		cout << it << " ";
	cout << endl;
	return 0;
}