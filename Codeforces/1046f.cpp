/*=======================
Author    : Shounak Dey
Filename  : 1046f.cpp
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

ll sim(map<ll,ll> &dp,ll a,ll x,ll f){
	if(dp.find(a) != dp.end())
		return dp[a];
	if(a>x){
		ll temp = a>>1;
		if((temp + (a&1))>=f)
			dp[a] = 1 + sim(dp,temp,x,f) + sim(dp,temp + (a&1)-f,x,f);
		else
			dp[a] = 1 + sim(dp,f+1,x,f) + sim(dp,a-f-1,x,f);
		return dp[a];
	}
	dp[a] = 0;
	return dp[a];
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	map<ll,ll> dp;
	REP(i,n)
		cin >> arr[i];
	ll x,f;
	cin >> x >> f;
	ll ans=0;
	REP(i,n)
		ans += f*sim(dp,arr[i],x,f);
	cout << ans << endl;
	return 0;
}