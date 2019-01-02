/*=======================
Author    : Shounak Dey
Filename  : 698a.cpp
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

int main(){
	fast_io;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	ll dp[n][3];
	dp[0][0] = 0;
	dp[0][1] = arr[0]&1;
	dp[0][2] = (arr[0]>>1)&1;
	FOR(i,1,n){
		dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		if(arr[i]&1)
			dp[i][1] = max(dp[i-1][0],dp[i-1][2])+1;
		else
			dp[i][1] = dp[i][0];
		if((arr[i]>>1)&1)
			dp[i][2] = max(dp[i-1][0],dp[i-1][1])+1;
		else
			dp[i][2] = dp[i][0];
	}
	cout << n-max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << endl;
	return 0;
}
