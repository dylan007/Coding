/*=======================
Author    : Shounak Dey
Filename  : 977d.cpp
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

void dfs(vector<int> &visited,vector<int> &path,int start,vector<vector<int>> adj){
	path.PB(start);
	visited[start] = 1;
	REP(i,adj[start].size()){
		if(!visited[adj[start][i]]){
			dfs(visited,path,adj[start][i],adj);
		}
	}
}

int check(vector<int> visited){
	REP(i,visited.size()){
		if(visited[i]==0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	map<ull,int> x;
	vector<ull> arr(n);
	REP(i,n){
		cin >> arr[i];
		x[arr[i]]=i;
	}
	vector<vector<int>> adj(n,vector<int>());
	REP(i,n){
		ull temp = arr[i];
		if((arr[i]%3 )== 0){
			temp /= 3;
			if(x.find(temp) != x.end())
				adj[i].PB(x[temp]);
		}
		temp = arr[i] * 2;
		if(x.find(temp) != x.end()){
			adj[i].PB(x[temp]);
		}
	}
	vector<int> ans;
	REP(i,n){
		vector<int> path;
		vector<int> visited(n,0);
		dfs(visited,path,i,adj);
		if(check(visited)){
			ans = path;
			break;
		}
	}
	for(auto it:ans)
		cout << arr[it] << " ";
	cout << endl;
	return 0;
}
