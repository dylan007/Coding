/*=======================
Author    : Shounak Dey
Filename  : brute.cpp
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

#define MAX (ll)(1e18)

typedef struct point{
	ll x,y;
	bool operator <(const point &pt) const{
		if(x==pt.x)
			return y<pt.y;
		return x<pt.x;
	}
}point;

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	auto dist = [](point a,point b){
		return ((a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y));
	};
	vector<point> p(n);
	p[0].x = 0;
	p[0].y = arr[0];
	REP(i,n){
		p[i].x = i;
		p[i].y = p[i-1].y + arr[i];
	}
	ll ans = MAX;
	REP(i,n){
		FOR(j,i+1,n){
			if(dist(p[i],p[j])<ans){
				ans = dist(p[i],p[j]);
				error(i,j,ans);
			}
		}
	}
	// cout << fixed << setprecision(15);
	cout << ans << endl;
	return 0;
}