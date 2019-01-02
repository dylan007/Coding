/*=======================
Author    : Shounak Dey
Filename  : 611c.cpp
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
	ll n,m;
	cin >> n >> m;
	vector<string> b(n);
	REP(i,n)
		cin >> b[i];
	//Build DP
	vector<vector<ll>> dp(n,vector<ll>(m,0));
	REP(i,n){
		REP(j,m){
			if(i>0){
				if(b[i][j]=='.' && b[i-1][j]=='.')
					dp[i][j] += dp[i-1][j]+1;
				else
					dp[i][j] += dp[i-1][j];
			}
			if(j>0){
				if(b[i][j]=='.' && b[i][j-1]=='.')
					dp[i][j] += dp[i][j-1]+1;
				else
					dp[i][j] += dp[i][j-1];
			}
			if(i>0 && j>0)
				dp[i][j] -= dp[i-1][j-1];
			// error(i,j,dp[i][j]);
		}
	}
	// for(auto it: dp){
	// 	for(auto its:it)
	// 		cout << its << "\t";
	// 	cout << endl;
	// }
	ll q;
	cin >> q;
	while(q--){
		ll r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;c1--;r2--;c2--;
		ll ans=dp[r2][c2];
		if(r1>0)
			ans -= dp[r1-1][c2];
		if(c1>0)
			ans -= dp[r2][c1-1];
		if(r1>0 && c1>0)
			ans += dp[r1-1][c1-1];
		ll tmp=0;
		if(c1>0){
			FOR(i,r1,r2+1)
				tmp += (b[i][c1-1]=='.' && b[i][c1]=='.');
		}
		if(r1>0){
			FOR(i,c1,c2+1)
				tmp += (b[r1-1][i]=='.' && b[r1][i]=='.');
		}
		// cout << tmp << endl;
		cout << ans-tmp << endl;
	}
	return 0;
}