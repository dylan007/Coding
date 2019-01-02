/*=======================
Author    : Shounak Dey
Filename  : farida.cpp
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
	ll T;
	cin >> T;
	REP(test,T){
		cout << "Case " << test+1 << ": ";
		ll n;
		cin >> n;
		vector<ll> arr(n);
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		REP(i,n)
			cin >> arr[i];
		vector<vector<ll>> dp(n,vector<ll>(2,0));
		dp[0][0] = arr[0];
		dp[0][1] = 0;
		FOR(i,1,n){
			dp[i][0] = dp[i-1][1] + arr[i];
			dp[i][1] = max(dp[i-1][1],dp[i-1][0]);
		}
		cout << max(dp[n-1][0],dp[n-1][1]) << endl;
	}
	return 0;
}