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
int ans=0;

void bfs(vector<vector<int>> adj,int start,vector<int> &visited,int level){
	if(visited[start])
		return;
	visited[start] = 1;
	ans = max(ans,level);
	REP(i,adj[start].size()){
		if(!visited[adj[start][i]])
			bfs(adj,adj[start][i],visited,level+1);
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	set<string> users;
	locale loc;
	vector<pair<string,string>> posts;
	REP(i,n){
		string src,dst;
		cin >> src >> dst >> dst;
		transform(src.begin(), src.end(), src.begin(), ::tolower); 
		transform(dst.begin(),dst.end(),dst.begin(),::tolower);
		posts.PB(MK(dst,src));
		users.insert(src);
		users.insert(dst);
	}
	// for(auto it:users)
	// 	cout << it << " ";
	// cout << endl;
	map<string,int> index;
	
	int curr=0;
	for(auto it:users)
		index[it] = curr++;
	vector<vector<int>> adj(curr,vector<int>());
	for(auto it: posts){
		adj[index[it.first]].PB(index[it.second]);
		adj[index[it.second]].PB(index[it.first]);
	}
	// for(auto it:adj){
	// 	for(auto subit: it)
	// 		cout << subit << " ";
	// 	cout << endl;
	// }
	int start = index["polycarp"];
	vector<int> visited(n,0);
	bfs(adj,start,visited,1);
	cout << ans << endl;
	return 0;
}