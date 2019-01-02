/*=======================
Author    : Shounak Dey
Filename  : 788a.cpp
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
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	vector<ll> a(n,0),b(n,0);
	FOR(i,1,n)
		a[i] = b[i] = abs(arr[i]-arr[i-1]);
	for(ll i=0;i<n;i+=2)
		a[i] = 0-a[i];
	for(ll i=1;i<n;i+=2)
		b[i] = 0-b[i];
	ll ans=LLONG_MIN;
	ll msf=LLONG_MIN,meh=0;
	REP(i,n){
		meh += a[i];
		msf = max(meh,msf);
		if(meh<0)
			meh = 0;
		// error(msf,meh,a[i]);
	}
	ans = max(ans,msf);
	msf = LLONG_MIN,meh=0;
	REP(i,n){
		meh += b[i];
		msf = max(meh,msf);
		if(meh<0)
			meh = 0;
	}
	cout << max(ans,msf) << endl;
	return 0;
}