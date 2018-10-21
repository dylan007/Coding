/*=======================
Author    : Shounak Dey
Filename  : b.cpp
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

ll dfs(vector<vector<ll>> adj,vector<ll> visited,ll start,ll search,vector<ll> state,ll cost){
	if(state[start] == search){
		visited[start] = 1;
		return cost;
	}
	ll c=INT_MAX;
	visited[start] = 1;
	// error(start);]
	
	REP(i,visited.size()){
		if(!visited[i] && adj[start][i]>=0)
			c = min(dfs(adj,visited,i,search,state,cost+adj[start][i]),c);
	}
	return c;
}

int main()
{
	int T;
	cin >> T;
	REP(test,T){
		ll v,e;
		cin >> v >> e;
		vector<vector<ll>> adj(v,vector<ll>(v,-1));
		REP(i,e){
			ll x,y,w;
			cin >> x >> y >> w;
			x--;y--;
			adj[x][y] = w;
			adj[y][x] = w;
		}
		ll lim = 1<<v;
		lim--;
		map<ll,ll> cost;
		ll min = LONG_MAX;
		FOR(i,1,lim){
			vector<ll> state(v,0);
			ll temp=i,c=v-1;
			while(c>=0){
				if(temp&1)
					state[c] = 1;
				temp >>= 1;
				c--;
			}
			// for(auto it:state)
			// 	cout << it << " ";
			// cout << endl;
			ll currcost=0;
			REP(j,v){
				vector<ll> visited(v,0);
				// error(j);
				if(state[j])
					currcost += dfs(adj,visited,j,0,state,0);
				else
					currcost += dfs(adj,visited,j,1,state,0);
				// error(currcost);
			}
			if(cost.find(currcost) != cost.end())
				cost[currcost]++;
			else
				cost[currcost] = 1;
			// cout << currcost << endl;
			min = min>currcost?currcost:min;
		}
		cout << "Case #" << test+1 << ": " <<  cost[min] << endl;
	}	
	return 0;
}