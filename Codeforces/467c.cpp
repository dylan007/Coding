/*=======================
Author    : Shounak Dey
Filename  : 467c.cpp
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
	ll n,m,k;
	cin >> n >> m >> k;
	vector<ll> arr(n+1,0);
	FOR(i,1,n+1){
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	vector<vector<ll>> dp(n+10,vector<ll>(k+10,0));
	FOR(i,0,n+1){
		REP(j,k+1){
			if((i+m)<=n)
				dp[i+m][j+1] = max(dp[i+m][j+1],dp[i][j]+arr[i+m]-arr[i]);
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		}
	}
	// REP(j,k+1){
	// 	REP(i,n+1)
	// 		cout << dp[i][j] << ' ';
	// 	cout << endl;
	// }
	cout << dp[n][k] << endl;
	return 0;
}