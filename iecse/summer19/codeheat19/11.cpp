/*=======================
Author    : Shounak Dey
Filename  : 11.cpp
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

vector<vector<ll>> adj;
vector<ll> visited;
vector<ll> diam;

ll bfs(ll start){
	queue<ll> q;
	q.push(start);
	visited[start] = 1;
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		for(auto it: adj[curr]){
			if(!visited[it]){
				// cout << curr << " " << ep << " " << visited[ep] << endl;
				visited[it] = 1;
				diam[it] += diam[curr]+1;
				q.push(it);
			}
		}
	}
	return max_element(diam.begin(),diam.end())-diam.begin();
}

int main()
{
	fast_io;
	ll ans=0;
	TEST{
		ll k;
		cin >> k;
		adj = vector<vector<ll>>(k,vector<ll>());
		REP(i,k-1){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		visited = vector<ll>(k,0);
		diam = vector<ll>(k,0);
		ll farthest = bfs(0);
		visited = vector<ll>(k,0);
		diam = vector<ll>(k,0);
		farthest = bfs(farthest);
		ans += diam[farthest];
	}		
	cout << ans << endl;
	return 0;
}