/*=======================
Author    : Shounak Dey
Filename  : 466c.cpp
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

int main()
{
	ll n;
	cin >> n;
	vector<ll> arr(n),pre(n,0);
	REP(i,n) cin >> arr[i];
	pre[0] = arr[0];
	FOR(i,1,n) pre[i] = pre[i-1] + arr[i];
	ll ans=0;
	// if(pre[n-1] == 0){
	// 	ll c=0;
	// 	REP(i,n)
	// 		c += (pre[i]==0);
	// 	REP(i,n){
	// 		if(i<(n-1) && pre[i]==0){
	// 			c--;
	// 			ans += max(0ll,(c-(pre[i+1]==0)-1));
	// 		}
	// 	}
	// 	cout << ans << endl;
	// 	return 0;
	// }
	if((pre[n-1]%3) != 0){
		cout << 0 << endl;
		return 0;
	}
	ll temp=pre[n-1]/3;
	vector<int> cnt(n,0);
	FOR(i,1,n)
		cnt[i] = ((pre[n-1]-pre[i-1])==temp);
	for(int i=(n-2);i>=0;i--)
		cnt[i] += cnt[i+1];
	REP(i,n-2){
		if(pre[i]==temp)
			ans += cnt[i+2];
	}
	cout << ans << endl;
	return 0;
}