/*=======================
Author    : Shounak Dey
Filename  : 987c.cpp
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

#define INF 10000000000000000

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> s(n),c(n);
	REP(i,n)
		cin >> s[i];
	REP(i,n)
		cin >> c[i];
	ll dp[n][4];
	dp[0][1] = c[0];
	dp[0][2] = dp[0][3] = INF;
	FOR(i,1,n){
		dp[i][1] = dp[i][2] = dp[i][3] = INF;
		dp[i][1] = c[i];
		REP(j,i){
			if(s[i]>s[j]){
				dp[i][2] = min(dp[i][2],dp[j][1]+c[i]);
				dp[i][3] = min(dp[i][3],dp[j][2]+c[i]);
			}
		}
	}
	// REP(j,4){
	// 	REP(i,n)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	ll m = INF;
	REP(i,n)
		m = min(m,dp[i][3]);
	if(m==INF)
		cout << -1 << endl;
	else
		cout << m << endl;
	return 0;
}