/*=======================
Author    : Shounak Dey
Filename  : infi1803.cpp
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

ll powmod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	vector<ll> series;
	int curr=5;
	while(curr<=100000){
		series.PB(curr);
		curr+=3;
	}
	// for(auto it:series)
	// 	cout << it << " ";
	// cout << endl;
	vector<ll> pre(series.size()+1,0);
	ll n = series.size();
	FOR(i,1,n+1)
		pre[i] = (pre[i-1] + powmod(series[i-1],series[i-1]))%MOD;
	int q;
	cin >> q;
	while(q--){
		int l,r;
		int x,y;
		cin >> x >> y;
		if(x <= series[0])
			l=0;
		else{
			l = lower_bound(series.begin(),series.end(),x)-series.begin()-1;
			l += (y!=series[l]);
		}
		if(y >= series[n-1])
			r=n;
		else{
			r = lower_bound(series.begin(),series.end(),y)-series.begin();
			r += (y==series[r]);
		}
		// error(l,r,series[l],series[r],pre[l],pre[r]);
		cout << (MOD + pre[r]-pre[l])%MOD << endl;
	}
	return 0;
}