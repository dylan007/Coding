/*=======================
Author    : Shounak Dey
Filename  : 20.cpp
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

#define INF 1e18

int main()
{
	fast_io;
	ll n,m;
	cin >> n >> m;
	auto comp = [](pair<ll,ll> lhs,pair<ll,ll> rhs){
		return lhs.second > rhs.second; 
	};
	std::priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(comp)> q(comp);
	vector<ll> visited(n);
	vector<ll> dist(n,INF);
	vector<ll> parent(n,-1);
	vector<vector<pair<ll,ll>>> adj(n,vector<pair<ll,ll>>());
	REP(i,m){
		ll x,y,w;
		cin >> x >> y >> w;
		x--;y--;
		adj[x].PB(MK(y,w));
		adj[y].PB(MK(x,w));
	}
	dist[0] = 0;
	q.push({0,dist[0]});
	while(!q.empty()){
		// for(auto it: dist)
		// 	cout << it << " ";
		// cout << endl;
		auto curr = q.top();
		q.pop();
		// error(curr.first,curr.second);
		for(auto it: adj[curr.first]){
			ll ne = it.first;
			ll w = it.second;
			if(dist[ne] > (dist[curr.first] + w)){
				dist[ne] = dist[curr.first]+w;
				parent[ne] = curr.first;
				q.push({ne,dist[ne]});
			}
		}
	}
	// for(auto it: dist)
	// 	cout << it << " ";
	// cout << endl;
	if(dist[n-1]==INF){
		cout << -1 << endl;
		return 0;
	}
	vector<ll> ans;
	ll curr = n-1;
	while(curr != -1){
		ans.PB(curr+1);
		curr = parent[curr];
	}
	for(auto it=ans.rbegin();it!=ans.rend();it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}