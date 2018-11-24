/*=======================
Author    : Shounak Dey
Filename  : ec_p.cpp
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

int timer;
vector<pair<int,int>> ans;
vector<int> visited(1000,0),tin(1000,0),fup(1000,0);
vector<vector<int>> adj;

void dfs(int start,int parent = -1){
	visited[start] = 1;
	tin[start] = fup[start] = timer++;
	for(auto x: adj[start]){
		if(x == parent)
			continue;
		else if(visited[x])
			fup[start] = min(fup[start],tin[x]);
		else{
			dfs(x,start);
			fup[start] = min(fup[start],fup[x]);
			// error(x,start,fup[x],tin[start]);
			if(fup[x] > tin[start])
				ans.PB(MK(min(x,start)+1,max(x,start)+1));
		}
	}
}

int main()
{
	fast_io;
	int T;
	cin >> T;
	REP(test,T){
		cout << "Caso #" << test+1 << endl;
		int n,m;
		cin >> n >> m;
		vector<vector<int>> adj(n,vector<int>());
		visited = vector<int>(1000,0);
		tin = vector<int>(1000,0);
		fup = vector<int>(1000,0);
		adj = vector<vector<int>>(1000,vector<int>());
		REP(i,m){
			int x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		timer=0;
		ans.clear();
		REP(i,n){
			if(!visited[i])
				dfs(i);
		}
		sort(ans.begin(),ans.end(),[](const auto &lhs,const auto &rhs){
			if(lhs.first == rhs.first)
				return lhs.second < rhs.second;
			return lhs.first < rhs.first;
		});
		if(ans.size()==0){
			cout << "Sin bloqueos" << endl;
			continue;
		}
		cout << ans.size() << endl;
		for(auto it: ans)
			cout << it.first << " " << it.second << endl;
	}
	return 0;
}