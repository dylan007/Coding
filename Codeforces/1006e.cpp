/*=======================
Author    : Shounak Dey
Filename  : 1006e.cpp
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

void dfs(vector<vector<int>> &adj,vector<int> &stack,int start,vector<int> &visited,vector<int> &size){
	visited[start] = 1;
	size[start] = 1;
	stack.PB(start);
	// cout << start << endl;
	REP(i,adj[start].size()){
		if(!visited[adj[start][i]] && adj[start][i] != start){
			dfs(adj,stack,adj[start][i],visited,size);
			size[start] += size[adj[start][i]];
		}
	}
}


int main()
{
	int n,q;
	cin >> n >> q;
	vector<vector<int>> adj(n,vector<int>());
	REP(i,n-1){
		int x;
		cin >> x;
		adj[x-1].PB(i+1);
	}
	vector<int> stack;
	vector<int> visited(n,0);
	vector<int> size(n,0);
	dfs(adj,stack,0,visited,size);
	map<int,int> pos;
	// for(auto it:stack)
	// 	cout << it << " ";
	// cout << endl;
	REP(i,n)
		pos[stack[i]] = i;
	// cout << "done" << endl;
	while(q--){ 
		int x,k;
		cin >> x >> k;
		x--;
		if(size[x]>=k)
			cout << stack[pos[stack[x]] + k-1]+1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}