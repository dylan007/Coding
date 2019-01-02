/*=======================
Author    : Shounak Dey
Filename  : akbar.cpp
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

void bfs(ll start,vector<ll> &visited,vector<vector<ll>> adj,ll d){
	ll n = visited.size();
	vector<ll> depth(n,0);
	queue<ll> q;
	q.push(start);
	visited[start]++;
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		if(depth[curr] > d)
			break;
		for(auto it: adj[curr]){
			if(visited[it]==0){
				// error(curr,it);
				q.push(it);
				depth[it] = depth[curr]+1;
				if(depth[it]<=d)
					visited[it]++;
			}
		}
	}
	// error(start);
	// for(auto it: depth)
	// 	cout << it << " ";
	// cout << endl;
	// for(auto it: visited)
	// 	cout << it << " ";
	// cout << endl;
	return;
}

int main()
{
	fast_io;
	TEST{
		ll n,m,k;
		cin >> n >> m >> k;
		vector<vector<ll>> adj(n,vector<ll>());
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		vector<ll> s(n,-1);
		REP(i,k){
			ll x,y;
			cin >> x >> y;
			x--;
			s[x] = y;
		}
		vector<ll> fvisited(n,0);
		int f=0;
		REP(i,n){
			if(s[i]>=0){
				if(fvisited[i]==0){
					vector<ll> visited(n,0);
					vector<ll> depth(n,0);
					queue<ll> q;
					q.push(i);
					visited[i]++;
					while(!q.empty()){
						ll curr = q.front();
						q.pop();
						if(depth[curr] > s[i])
							break;
						for(auto it: adj[curr]){
							if(visited[it]==0){
								// error(curr,it);
								depth[it] = depth[curr]+1;
								if(depth[it]<=s[i])
									visited[it]++;
								if(fvisited[it]!=0){
									f = 1;
									break;
								}
								fvisited[it]=1;
								q.push(it);
							}
						}
						if(f)
							break;
					}
				}
				else{
					f=1;
					break;
				}
			}
		}
		for(auto it: fvisited){
			if(it != 1){
				f=1;
				break;
			}
		}
		if(f)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}