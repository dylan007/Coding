/*=======================
Author    : Shounak Dey
Filename  : submerge.cpp
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

#define MAX 100010

vector<int> low(MAX,0),disc(MAX,0),parent(MAX,-1),visited(MAX,0);

int t=0,ans=0;

void dfs(vector<vector<int>> adj, int start){
	visited[start] = 1;
	disc[start] = low[start] = t+1;
	int child = 0;
	t++;
	REP(i,adj[start].size()){
		int n = adj[start][i];
		if(n==start)
			continue;
		if(!visited[n]){
			child++;
			parent[n] = start;
			dfs(adj,n);
			low[start] = min(low[start],low[n]);
			if(parent[start]==-1 && child>1)
				ans++;
			if(parent[start]!=-1 && low[n]>=disc[start])
				ans++;
		}
		else
			low[start] = min(low[start],disc[n]);
	}
	return;
}

int main()
{
	// ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m;
	read(n);read(m);
	while(!(n==0 && m==0)){
		vector<vector<int>> adj(n,vector<int>());
		fill(low.begin(),low.begin()+n,0);
		fill(visited.begin(),visited.begin()+n,0);
		fill(disc.begin(),disc.begin()+n,0);
		fill(parent.begin(),parent.begin()+n,-1);
		while(m--){
			int x,y;
			read(x);read(y);
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		dfs(adj,0);
		cout << ans << endl;
		read(n);read(m);
	}
	return 0;
}