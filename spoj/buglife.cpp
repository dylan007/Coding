/*=======================
Author    : Shounak Dey
Filename  : buglife.cpp
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

ll find(vector<ll> parent,ll x){
	if(x != parent[x])
		parent[x] = find(parent,parent[x]);
	return parent[x]; 
}

int main()
{
	fast_io;
	ll T;
	cin >> T;
	REP(test,T){
		cout << "Scenario #" << test+1 << ":" << endl;
		ll n,m;
		cin >> n >> m;
		vector<vector<ll>> adj(n,vector<ll>());
		vector<ll> parent(n),size(n,1);
		vector<ll> parity(n,0);
		REP(i,n)
			parent[i] = i;
		vector<ll> bip(n,1);
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			ll rootx = find(parent,x);
			ll rooty = find(parent,y);
			if(rootx == rooty){
				if(parity[rootx]==parity[rooty])
					bip[rootx] = 0;
			}
			else{
				if(size[rootx] < size[rooty]){
					parent[rootx] = rooty;
					size[rooty] += size[rootx];
					 
				}
			}
			adj[x].PB(y);
			adj[y].PB(x);
		}
	}
	return 0;
}