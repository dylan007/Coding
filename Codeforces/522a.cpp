/*=======================
Author    : Shounak Dey
Filename  : 522a.cpp
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

ll ans=0;

void bfs(vector<ll> visited,vector<vector<ll>> adj,ll start){
	queue<ll> q;
	q.push(start);
	vector<ll> level(visited.size(),0);
	level[start]=1;
	visited[start] = 1;		
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		for(auto it:adj[curr]){
			if(!visited[it]){
				visited[it] = 1;
				level[it] = level[curr]+1;
				q.push(it);
			}
		}
	}
	for(auto it: level)
		ans = max(it,ans);
}

int main()
{
	fast_io;
	ll m;
	cin >> m;
	ll curr=0;
	set<string> users;
	map<string,ll> pos;
	vector<vector<ll>> adj(20010,vector<ll>());
	while(m--){
		string a,b,c;
		cin >> a >> c >> b;
		transform(a.begin(),a.end(),a.begin(),::tolower);
		transform(b.begin(),b.end(),b.begin(),::tolower);
		if(users.find(a)==users.end()){
			users.insert(a);
			pos[a] = curr++;
		}
		if(users.find(b)==users.end()){
			users.insert(b);
			pos[b] = curr++;
		}
		// cout << pos[a] << " " << pos[b] << endl;
		adj[pos[a]].PB(pos[b]);
	}
	vector<string> fu(users.size());
	map<string,ll>::iterator it = pos.begin();
	while(it != pos.end()){
		fu[it->second] = it->first;
		it++;
	}
	ll n = users.size();
	vector<ll> visited(n,0);
	ans=0;
	REP(i,n){
		visited = vector<ll>(n,0);
		bfs(visited,adj,i);
	}
	cout << ans << endl;
	return 0;
}