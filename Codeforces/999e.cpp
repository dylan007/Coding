/*=======================
Author    : Shounak Dey
Filename  : 999e.cpp
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

int bfs(vector<vector<int>> adj,vector<int> &visited,int start,int flag){
	queue<int> q;
	q.push(start);
	int ans=0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visited[x] = flag;
		ans++;
		for(auto it:adj[x]){
			if(visited[it] == 0)
				q.push(it);
		}
	}
	return ans;
}

int main()
{
	int n,m,s;
	cin >> n >> m >> s;
	vector<vector<int>> adj(n,vector<int>());
	map<int,int> out;
	REP(i,n)
		out[i] = 0;
	REP(i,m){
		int x,y;
		cin >> x >> y;
		x--;y--;
		out[x]++;
		adj[x].PB(y);
	}
	vector<int> visited(n,0);
	bfs(adj,visited,s-1,1);
	vector<int> good(visited);
	// for(auto it:visited)
	// 	cout << it <<" ";
	// cout << endl;
	priority_queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		if(good[i]==0 && visited[i]==0)
			out[i] = bfs(adj,visited,start,flag);
	}
	vector<pair<int,int>> unv;
	while(!q.empty()){
		unv.PB(q.top());
		q.pop();
	}
	int curr=2;
	REP(i,unv.size()){
		pair<int,int> temp = unv[i];
		if(visited[temp.second] == 0)
			bfs(adj,visited,temp.second,curr++);
	}
	set<int> scc;
	for(auto it:visited){
		scc.insert(it);
		// cout << it << " ";
	}
	// cout << endl;
	cout << scc.size()-1 << endl;
	return 0;
}