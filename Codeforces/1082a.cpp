/*=======================
Author    : Shounak Dey
Filename  : 1082a.cpp
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

#define INF (ll)1e+12

int main()
{
	fast_io;
	TEST{
		ll n,x,y,d;
		cin >> n >> x >> y >> d;
		ll ans=INF;	
		auto dist = [d](ll a,ll b){
			return (abs(a-b) + (abs(d-1)))/d;
		};
		ll l = abs(x-y);
		if((l%d)==0)
			ans = min(ans,dist(x,y));
		l = y-1;
		if((l%d)==0)
			ans = min(ans,dist(1,x)+dist(1,y));
		l = n-y;
		if((l%d)==0)
			ans = min(ans,dist(n,x)+dist(n,y));
		if(ans==INF)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}