/*=======================
Author    : Shounak Dey
Filename  : b.cpp
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
	int T;
	cin >> T;
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll n;
		cin >> n;
		string a;
		cin >> a;
		// vector<ll> pre(n);
		// pre[0] = a[0]-'0';
		// FOR(i,1,n)
		// 	pre[i] = pre[i-1] + a[i]-'0';
		// ll x = n/2 + n%2;
		// ll ans=0;
		// REP(i,n-x+1){
		// 	ll l,r;
		// 	if(i==0)
		// 		l = 0;
		// 	else
		// 	 	l = pre[i-1];
		// 	r = pre[i+x-1];
		// 	ans = max(ans,r-l);
		// }
		// cout << ans << endl;
		ll curr=0,ans=0;
		ll x = n/2 + n%2;
		REP(i,x)
			curr += a[i]-'0';
		ans = max(ans,curr);
		ll i=0;
		while((i+x-1)<n){
			curr -= a[i]-'0';
			i++;
			curr += a[i+x-1]-'0';
			ans = max(ans,curr);
		}
		cout << ans << endl;
	}
	return 0;
}