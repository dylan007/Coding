/*=======================
Author    : Shounak Dey
Filename  : buglife.cpp
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
#define popc(a) __ builtin_popcount(a) // count set bits
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

ll find(vector<ll> &parent,ll x){
	if(x != parent[parent[x]])
		parent[x] = find(parent,parent[x]);
	return parent[x];
}

void un(vector<ll> &parent,vector<ll> &size,ll x,ll y){
	ll rootx = find(parent,x);
	ll rooty = find(parent,y);
	if(rootx != rooty){
		if(size[rootx]>size[rooty]){
			size[rootx] += size[rooty];
			parent[rooty] = rootx;
		}
		else{
			size[rooty] += size[rootx];
			parent[rootx] = rooty; 
		}
	}
	return;
}

ll bfs(vector<vector<ll>> adj,ll start,ll end){
	queue<ll> q;
	int n = adj.size();
	vector<ll> visited(n,0);
	q.push(start);
	map<ll,ll> depth;
	depth[start] = 0;
	visited[start] = 1;
	while(!q.empty()){
		ll x = q.front();
		q.pop();
		ll temp = depth[x];
		// error(x,temp);
		if(x == end)
			return temp;
		// cout << x << endl;
		REP(i,adj[x].size()){
			// cout << adj[x][i] << " ";
			if(!visited[adj[x][i]]){
				depth[adj[x][i]] = temp+1;
				visited[adj[x][i]] = 1;
				q.push(adj[x][i]);
			}
		}
		// cout << endl;
	}	
	return depth[end];
}

int main()
{
	int T;
	cin >> T;
	FOR(test,1,T+1){
		cout << "Scenario #" << test << ":" << endl;
		ll n,m;
		cin >> n >> m;
		vector<ll> parent(n),size(n);
		REP(i,n){
			parent[i] = i;
			size[i] = 1;
		}
		ll flag=0;
		vector<vector<ll>> adj(n,vector<ll>());
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			ll rootx = find(parent,x);
			ll rooty = find(parent,y);
			if(rootx == rooty){
				// cout << "Cycle " << x << " " << y << endl;
				ll len = bfs(adj,x,y);
				// cout << len << endl;
				if((len%2) == 0)
					flag=1;
			}
			else{
				adj[x].PB(y);
				adj[y].PB(x);
				un(parent,size,x,y);
			}
		}
		if(flag)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;
	}
	return 0;
}
