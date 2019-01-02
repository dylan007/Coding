/*=======================
Author    : Shounak Dey
Filename  : 1093d.cpp
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

#define MOD 998244353
#define MAXN 300010

vector<ll> color,cc(2,0);
vector<vector<ll>> adj;
ll flag=0;

void dfs(ll start,ll c){
	color[start] = c;
	cc[c]++;
	for(auto it: adj[start]){
		if(color[it] == -1)
			dfs(it,1-c);
		if(color[start] == color[it]){
			flag=1;
			return;
		}
	}
}

int main()
{
	fast_io;
	vector<ll> mx(MAXN,0);
	mx[0] = 1;
	FOR(i,1,MAXN)
		mx[i] = (2 * mx[i-1])%MOD;
	TEST{
		ll n,m;
		cin >> n >> m;
		adj = vector<vector<ll>>(n,vector<ll>());
		color = vector<ll>(n,-1);
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adj[x].PB(y);
			adj[y].PB(x);	
		}
		ll ans=1;
		REP(i,n){
			if(color[i]==-1){
				flag=0;
				cc[0] = cc[1] = 0;
				dfs(i,0);
				if(flag)
					break;
				// for(auto it:cc)
				// 	cout << it << " ";
				// cout << endl;
				ans = (ans * (mx[cc[0]] + mx[cc[1]])%MOD)%MOD;
			}
		}
		// error(flag,ans);
		cout << ((!flag)?ans:0) << endl;
	}	
	return 0;
}