/*=======================
Author    : Shounak Dey
Filename  : 59e.cpp
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

typedef struct s{
	ll x,y,z;
	bool operator<(const s& t) const{
		return x<t.x || ((x>=t.x) && (y<t.y)) || (x>=t.x && y>=t.y && z<t.z);
	}
}s;

int main()
{
	fast_io;
	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<ll>> adj(n,vector<ll>());
	REP(i,m){
		ll x,y;
		cin >> x >> y;
		adj[x-1].PB(y-1);
		adj[y-1].PB(x-1);
	}
	set<s> trips;
	REP(i,k){
		s temp;
		cin >> temp.x >>  temp.y >> temp.z;
		trips.insert(temp);
	}
	vector<ll> visited(n,0);
	vector<ll> parent(n,-1);
	queue<ll> q;
	q.push(0);
	visited[0] = 1;
	parent[0] = 0;
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		for(auto it:adj[curr]){
			if(visited[it]==0){
				ll p = curr;
				ll pp = parent[p];
				if(p!=pp){
					s tmp;
					tmp.x = pp+1;
					tmp.y = p+1;
					tmp.z = it+1;
					error(curr,pp,p);
					cout << tmp.x << " " << tmp.y << " " << tmp.z << endl;
					if(trips.find(tmp) != trips.end())
						continue;
				}
				visited[it]=1;
				q.push(it);
				parent[it] = curr;
			}
		}
	}
	if(!visited[n-1]) 
		cout << -1 << endl;
	else{
		vector<ll> ans;
		ll curr = n-1;
		while(curr != 0){
			ans.PB(curr);
			curr = parent[curr];
		}
		ans.PB(0);
		cout << ans.size() - 1 << endl;
		for(auto it=ans.rbegin();it!=ans.rend();it++)
			cout << (*it) + 1 << " ";
		cout << endl;
	}
	return 0;
}