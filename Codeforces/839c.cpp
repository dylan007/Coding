/*=======================
Author    : Shounak Dey
Filename  : 839c.cpp
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
	ll n;
	cin >> n;
	vector<vector<ll>> adj(n,vector<ll>());
	REP(i,n-1){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	vector<ll> visited(n,0);
	double ans=0;
	vector<ll> pl(n,0);
	vector<double> p(n,0);
	queue<ll> q;
	q.push(0);
	p[0]=1.0;
	vector<ll> fin(n,0);
	while(!q.empty()){
		auto curr = q.front();
		q.pop();
		visited[curr] = 1;
		double c = 0;
		for(auto it: adj[curr])
			c += 1.0*(!visited[it]);
		if(c==0.0){
			fin[curr]=1;
			continue;
		}
		for(auto it: adj[curr]){
			if(!visited[it]){
				p[it] = (p[curr]*(1.0/c));
				pl[it] = pl[curr]+1;
				q.push(it);
			}
		}
	}
	REP(i,n)
		ans += ((double)fin[i]*p[i]*pl[i]);
	// for(auto it: p)
	// 	cout << it << " ";
	// cout << endl;
	// for(auto it: pl)
	// 	cout << it << " ";
	// cout << endl;
	cout << setprecision(9) << fixed;
	cout << ans << endl;
	return 0;
}