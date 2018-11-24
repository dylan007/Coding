/*=======================
Author    : Shounak Dey
Filename  : pritree2.cpp
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

vector<vector<ll>> sets;

void gen(vector<ll> arr,vector<ll> s,int curr,int n,int pos,int l){
	if(pos>=l){
		sets.PB(s);
		return;
	}
	if(curr>=n)
		return;
	s.PB(arr[curr]);
	gen(arr,s,curr+1,n,pos+1,l);
	s.pop_back();
	gen(arr,s,curr+1,n,pos,l);
	return;
}

vector<vector<ll>> gentree(vector<ll> perm,vector<pair<ll,ll>> edges,ll n){
	vector<vector<ll>> adj(n,vector<ll>());
	for(auto it:perm){
		ll x = it-1;
		adj[edges[x].first].PB(edges[x].second);
		adj[edges[x].second].PB(edges[x].first);
	}
	return adj;
}

int dfs(vector<vector<ll>> adj,vector<ll> &visited,int start,int n){
	visited[start]=1;
	int f=0;
	for(auto it:adj[start]){
		if(visited[it])
			f=1;
		if(!visited[it])
			f |= dfs(adj,visited,it,n);
	}
	return f;
}

int checkTree(vector<vector<ll>> adj,ll n){
	vector<ll> visited(n,0);
	if(dfs(adj,visited,0,n))
		return 0;
	for(auto it:visited){
		if(it == 0)
			return 0;
	}
	return 1;
}

ll eval(vector<vector<ll>> adj,vector<ll> wt,ll n){
	ll score=0;
	vector<pair<ll,ll>> edges;
	
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	vector<pair<ll,ll>> edges;
	REP(i,n){
		FOR(j,i+1,n)
			edges.PB(MK(i,j));
	}	
	vector<ll> perm;
	REP(i,(n*(n-1))/2)
		perm.PB(i+1);
	gen(perm,vector<ll>(),0,perm.size(),0,n-1);
	ll l = edges.size();
	vector<vector<ll>> ans;
	REP(i,sets.size()){
		vector<vector<ll>> adj = gentree(perm,edges,n);
		if(checkTree(adj,n)){
			ll score = eval(adj,wt,n);
		}
	}
	return 0;
}