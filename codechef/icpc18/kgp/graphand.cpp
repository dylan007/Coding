/*=======================
Author    : Shounak Dey
Filename  : graphand.cpp
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

const ll INF = 1e18;

typedef struct edge{
	ll p,c,v;
}edge;


ll dijkstra(vector<vector<edge>> adj,ll mask,ll s,ll t){
	ll n = adj.size();
	// auto cmp = [](pair<ll,ll> a,pair<ll,ll> b){
	// 	return a.S < b.S;
	// };
	set<pair<ll,ll>> active;
	vector<ll> dist(n,INF);
	dist[s] = 0;
	active.insert({dist[s],s});
	while(!active.empty()){
		ll a = active.begin()->S;
		active.erase(active.begin());
		if(a==t)
			break;
		for(auto it:adj[a]){
			ll b = it.p;
			ll c = it.c;
			ll v = it.v;
			if((v&mask)!=mask)
				continue;
			if(dist[b] > (dist[a]+c)){
				active.erase({dist[b],b});
				dist[b] = dist[a] + c;
				active.insert({dist[b],b});
			}
		}
	}
	return (dist[t]==INF)?-1:dist[t];
}

int main()
{
	fast_io;
	ll n,m;
	cin >> n >> m;
	vector<vector<edge>> adj(n,vector<edge>());
	REP(i,m){
		ll x,y,c,v;
		cin >> x >> y >> c >> v;
		x--;y--;
		edge tmp = {y,c,v};
		adj[x].PB(tmp);
		tmp.p = x;
		adj[y].PB(tmp);
	}
	ll s,t,k;
	cin >> s >> t >> k;
	s--;t--;
	ll tmp = k,pos=0,ans=INF;
	while(pos<63){
		if(!(tmp&1)){
			ll mask = (k | (1ll<<pos))&(~((1ll<<pos)-1));
			ll ret = dijkstra(adj,mask,s,t);
			if(ret != -1)
				ans = min(ans,ret);
			// error(mask,ret);
		}
		pos ++;
		tmp >>= 1;
	}
	ll ret = dijkstra(adj,k,s,t);
	if(ret != -1)
		ans = min(ans,ret);
	// error(k,ret);
	if(ans==INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}