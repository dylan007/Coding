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
	TEST{
		ll n,k;
		cin >> n >> k;
		string a;
		cin >> a;
		vector<ll> arr(n);
		REP(i,n){
			if(a[i]=='R')
				arr[i] = 0;
			else if(a[i]=='G')
				arr[i] = 1;
			else
				arr[i] = 2;
		}
		ll dp[n][3];
		REP(i,3)
			dp[0][i] = (arr[0]!=i);
		ll ans=LONG_MAX;
		FOR(i,1,k){
			REP(j,3){
				dp[i][j] = dp[i-1][(j+2)%3] + (arr[i]!=j);
			}
		}
		REP(j,3)
			ans = min(ans,dp[k-1][j]);
		FOR(i,k,n){
			REP(j,3){
				ll ind = (j-(k)%3 + 3)%3;
				ll sub = (arr[i-k]!=ind);
				dp[i][j] = dp[i-1][(j+2)%3] + (arr[i]!=j) - sub;
				ans = min(ans,dp[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

