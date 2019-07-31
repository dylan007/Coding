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
vector<vector<ll>> adj;
vector<ll> vis;
vector<ll> visited;
vector<ll> ep;
map<pair<ll,ll>,ll> emap;
vector<ll> s;
void dfs(ll start,ll depth){
	if(depth&1)
		ep[start]++;
	for(auto it:adj[start]){
		ll ind = emap[MK(start,it)];
		if(vis[ind])
			continue;
		vis[ind]=1;
		dfs(it,depth+1);
	}
}

void topo(ll start){
	visited[start] = 1;
	for(auto it:adj[start]){
		if(visited[it]==0)
			topo(it);
	}
	s.push_back(start);
	return;
}

int main()
{
	fast_io;
	TEST{
		ll n,m,x;
		cin >> n >> m >> x;
		adj = vector<vector<ll>>(n,vector<ll>());
		emap = map<pair<ll,ll>,ll>();
		s = vector<ll>();
		REP(i,m){
			ll a,b;
			cin >> a >> b;
			a--;
			b--;
			adj[a].PB(b);
			emap[MK(a,b)] = i;
		}
		x--;
		vis = vector<ll>(m,0);
		ep = vector<ll>(n,0);
		visited = vector<ll>(n,0);
		topo(x);
		for(auto it: s)
			cout << it << " ";
		cout << endl;
		for(auto it:ep)
			cout << it << " ";
		cout << endl;
		
	}
	return 0;
}

