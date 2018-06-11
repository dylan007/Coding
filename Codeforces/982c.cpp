/*=======================
Author    : Shounak Dey
Filename  : 982c.cpp
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
map<pair<int,int>,int> valid;
vector<int> arr;


int dfs(vector<int> &visited,vector<vector<int>> &adj, int start){
	visited[start] = 1;
	int curr = 0;
	REP(i,adj[start].size()){
		int n=adj[start][i];
		if(!visited[n]){
			int sub = dfs(visited,adj,n);
			// error(start,sub,n);
			if((sub%2) == 0){
				if(valid.find(MK(start,n)) != valid.end())
					valid[MK(start,n)] = 0;
				else
					valid[MK(n,start)] = 0;
				ans++;
				arr.PB(sub);
			}	
			else
				curr += sub;
		}
	}
	return curr+1;
}

int checkfor(vector<vector<int>> adj,vector<int> &visited,int start){
	visited[start] = 1;
	int curr=0;
	for(int i=0;i<adj[start].size();i++){
		int n=adj[start][i];
		if(!visited[n]){
			int sub = dfs(visited,adj,n);
			curr += sub;
		}
	}
	return curr+1;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n,vector<int>());
	REP(i,n-1){
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
		valid[MK(x,y)] = 1;
	}
	vector<int> visited(n,0);
	arr.PB(dfs(visited,adj,0));
	// for(auto it:arr)
	// 	cout << it << " ";
	// cout << endl;
	vector<int>temp(n,0);
	visited = temp;
	int flag=0;
	// cout << ans << endl;
	// vector<vector<int>> temp2(n,vector<int>());
	// adj = temp2;
	// map<pair<int,int>,int>::iterator it = valid.begin();
	// while(it!=valid.end()){
	// 	if(it->second){
	// 		int x,y;
	// 		x = it->first.first;
	// 		y = it->first.second;
	// 		adj[x].PB(y);
	// 		adj[y].PB(x);
	// 	}
	// 	it++;
	// }
	// int check = checkfor(adj,visited,0);
	// // cout << check << endl;
	// flag = check%2;
	// REP(i,n){
	// 	if(visited[i])
	// 		continue;
	// 	check = checkfor(adj,visited,i);
	// 	// error(check);
	// 	flag |= (check%2);
	// }
	for(auto it: arr){
		if(it%2)
			flag=1;
	}
	if(flag)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}