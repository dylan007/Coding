/*=======================
Author    : Shounak Dey
Filename  : chsign.cpp
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

ll check(vector<ll> arr,ll x){
	if(x==0)
		return arr[x+1]>arr[x];
	else if(x==(arr.size()-1))
		return arr[x-1]>arr[x];
	else
		return (arr[x-1]>arr[x])&&(arr[x+1]>arr[x]);
}

int main()
{
	TEST{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		vector<vector<ll>> dp(n,vector<ll>(2,0));
		dp[0][0] = arr[0];
		if(check(arr,0))
			dp[0][1] = 0-arr[0];
		else
			dp[0][1] = arr[0];
		FOR(i,1,n){
			if(check(arr,i)){
				ll x = min(dp[i-1][0],dp[i-1][1]);
				dp[i][0] = x+arr[i];
				dp[i][1] = x-arr[i];
				if(dp[i][1] <= 0)
					dp[i][1] = dp[i][0];
 			}
 			else{
 				ll x = min(dp[i-1][0],dp[i-1][1]);
 				dp[i][0] = dp[i][1] = x+arr[i];
 			}
		}
		REP(i,n){
			if(dp[i][0] > dp[i][1])
				cout << 0-arr[i] << " ";
			else
				cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
