/*=======================
Author    : Shounak Dey
Filename  : 1077f.cpp
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

ll ans=-1;

void trav(vector<ll> arr,ll n,ll k,ll x,ll curr,ll start){
	curr += arr[start];
	x--;
	// error(start,x);
	if(x==0){
		ll rem = n-start-1;
		// error(start,rem,curr);
		if(rem < k)
			ans = max(curr,ans);
		return;
	}
	for(int i=start+1;i<min(start+k+1,n);i++)
		trav(arr,n,k,x,curr,i);
	return;
}

int main()
{
	fast_io;
	ll n,k,x;
	cin >> n >> k >> x;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	REP(i,k)
		trav(arr,n,k,x,0,i);
	cout << ans << endl;
	return 0;
}