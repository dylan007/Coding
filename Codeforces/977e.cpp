/*=======================
Author    : Shounak Dey
Filename  : 977e.cpp
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

int dfs(vector<int> &visited,vector<int> &component,int start,vector<vector<int>> adj,int parent){
	visited[start] = 1;
	component.PB(start);
	int flag=0;
	for(auto it: adj[start]){
		if(!visited[it])
			flag |= dfs(visited,component,it,adj,start);
		else{
			if(parent != it)
				flag=1;
		}
	}
	return flag;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n,vector<int>());
	vector<int> deg(n,0);
	while(m--){
		int x,y;
		cin >> x >> y;
		x--;y--;
		deg[x]++;
		deg[y]++;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	vector<int> visited(n,0);
	int ans=0;
	REP(i,n){
		int f=0;
		if(visited[i])
			continue;
		vector<int> component;
		int c = dfs(visited,component,i,adj,-1);
		f = 1;
		for(auto it:component)
			f &= (deg[it]==2);
		// error(c,i,f);
		// cout << endl;
		if(c&f)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
