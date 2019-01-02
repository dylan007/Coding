/*=======================
Author    : Shounak Dey
Filename  : 796d.cpp
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

int main()
{
	fast_io;
	ll n,k,d;
	cin >> n >> k >> d;
	vector<ll> po(n,0);
	REP(i,k){
		ll x;
		cin >> x;
		po[x-1]=1;
	}
	vector<vector<ll>> adj(n,vector<ll>());
	map<pair<ll,ll>,ll> el;
	REP(i,n-1){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
		el[{x,y}] = i;
	}
	vector<ll> ein(n-1,0);
	vector<ll> ans;
	vector<ll> visited(n,0);
	vector<ll> l(n,0);
	queue<ll> q;
	REP(i,k){
		if(po[i]){
			q.push(i);
			visited[i] = 1;
		}
	}
	while(!q.empty()){
		ll curr = q.front();
		q.pop();
		for(auto it: adj[curr]){
			ll index;
			if(el.find({curr,it}) != el.end())
				index = (el[{curr,it}]);
			else
				index = (el[{it,curr}]);
			if(visited[it]){
				// error(curr,it,ein[index]);
				if(ein[index]==0)
					ans.PB(index);
			}
			else{
				l[it] = l[curr] + 1;
				visited[it] = 1;
				q.push(it);
				if(!po[it])
					ein[index] = 1;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto it:ans)
		cout << it+1 << " ";
	cout << endl;
	return 0;
}