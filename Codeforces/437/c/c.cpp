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

typedef struct edge{
	ll x,y,w;
	edge(ll x,ll y,ll w): x(x),y(y),w(w) {};
}e;

vector<ll> parent,size;

ll find(ll x){
	while(x != parent[x])
		x = find(parent[x]);
	return x;
}

int main()
{
	fast_io;
	ll n,m;
	cin >> n >> m;
	vector<ll> v(n);
	parent = vector<ll>(n,0);
	size = vector<ll>(n,1);
	REP(i,n){
		cin >> v[i];
		parent[i] = i;
	}
	vector<e> E;
	REP(i,m){
		ll x,y,w;
		cin >> x >> y;
		x--;y--;
		E.PB(edge(x,y,v[x]));
		E.PB(edge(x,y,v[y]));
	}
	sort(E.begin(),E.end(),[](e a,e b){
		return a.w < b.w;
	});
	ll ans=0;
	for(auto it:E){
		ll rootx = find(it.x);
		ll rooty = find(it.y);
		if(rootx == rooty)
			continue;
		ans += it.w;
		if(size[rootx] >= size[rooty]){
			parent[rooty] = rootx;
			size[rootx] += size[rooty];
		}
		else{
			parent[rooty] = rootx;
			size[rooty] += size[rootx];
		}
	}
	cout << ans << endl;
	return 0;
}

