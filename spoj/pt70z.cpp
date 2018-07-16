/*=======================
Author    : Shounak Dey
Filename  : pt70z.cpp
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

int bfs(vector<vector<int>> adj,int start,vector<int> &level){
	queue<int> q;
	q.push(start);
	level[start] = 0;
	int m=0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		REP(i,adj[p].size()){
			if(level[adj[p][i]] == -1){
				level[adj[p][i]] = level[p]+1;
				q.push(adj[p][i]);
				m = max(m,level[adj[p][i]]);
			}
		}
	}
	REP(i,level.size()){
		if(level[i] == m)
			return i;
	}
	return start;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	read(n);
	if(n==0){
		cout << 0 << endl;
		return 0;
	}
	vector<vector<int>> adj(n,vector<int>());
	REP(i,n-1){
		int x,y;
		read(x);read(y);
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	vector<int> level(n,-1);
	int index=bfs(adj,0,level);
	// cout << index << endl;
	fill(level.begin(),level.end(),-1);
	index = bfs(adj,index,level);
	cout << level[index] << endl;
	return 0;
}