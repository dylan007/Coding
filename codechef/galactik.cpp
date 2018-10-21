/*=======================
Author    : Shounak Dey
Filename  : galactik.cpp
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

ll find(vector<ll> &parent,ll x){
	if(parent[x] != x)
		parent[x] = find(parent,parent[x]);
	return parent[x];
}

void update(vector<ll> &parent, vector<ll> &size, ll x, ll y){
	ll rootx = find(parent,x);
	ll rooty = find(parent,y);
	if(rootx == rooty)
		return;
	if(size[rootx]>size[rooty]){
		parent[rooty] = rootx;
		size[rootx] += size[rooty];
	}
	else{
		parent[rootx] = rooty;
		size[rooty] += size[rootx];
	}
	return;
}

int main()
{
	ll n,m;
	readl(n);readl(m);
	vector<ll> parent(n,0),size(n,1);
	REP(i,n)
		parent[i] = i;
	REP(i,m){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		update(parent,size,x,y);
	}
	map<ll,ll> c;
	ll cmin = INT_MAX;
	REP(i,n)
		c[parent[i]]=INT_MAX;
	REP(i,n){
		ll x;
		cin >> x;
		if(x>=0)
			c[parent[i]] = min(c[parent[i]],x);
	}
	ll f=0,ans=0;
	for(auto it:c){
		if(it.second == INT_MAX){
			f=1;
			break;
		}
		cmin = min(it.second,cmin);
		ans += it.second;
	}
	if(f)
		cout << "-1" << endl;
	else if(c.size()==1)
		cout << 0 << endl;
	else
		cout << ans + (c.size()-2)*cmin << endl;
	return 0;
}