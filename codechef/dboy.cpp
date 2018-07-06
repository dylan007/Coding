/*=======================
Author    : Shounak Dey
Filename  : dboy.cpp
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

#define inf 100000007

vector<int> solve(vector<int> h,int x){
	int n = h.size();
	vector<int> dp(x+1,inf);
	REP(i,n){
		if(h[i]>x)
			continue;
		dp[h[i]] = 1;
	}
	FOR(i,1,x+1){
		if(dp[i]==inf)
			continue;
		REP(j,n){
			int ele = i+h[j];
			if(ele > x)
				continue;
			dp[ele] = min(dp[ele],dp[i]+1);
		}
	}
	return dp;
}

int main()
{
	TEST{
		int n;
		cin >> n;
		vector<int> k(n);
		int x = INT_MIN;
		REP(i,n){
			cin >> k[i];
			k[i] <<= 1;
			x = max(k[i],x);
		}
		vector<int> h(n);
		REP(i,n)
			cin >> h[i];
		vector<int> dp = solve(h,x);
		int ans=0;
		// for(auto it:dp)
		// 	cout << it << " ";
		// cout << endl;
		REP(i,n) ans += dp[k[i]];
		cout << ans << endl;
	}
	return 0;
}