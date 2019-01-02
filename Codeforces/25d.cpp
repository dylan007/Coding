/*=======================
Author    : Shounak Dey
Filename  : 25d.cpp
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

ll find(vector<ll> &parent,ll x){
	if(x != parent[x])
		parent[x] = find(parent,parent[x]);
	return parent[x];
}

void un(vector<ll> &parent,vector<ll> &size,ll x,ll y){
	parent[x] = y;
	return;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> parent(n),size(n,1);
	REP(i,n)
		parent[i] = i;
	vector<pair<ll,ll>> edges;
	REP(i,n-1){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		ll rootx = find(parent,x);
		ll rooty = find(parent,y);
		// error(x,y,rootx,rooty);
		if(rootx == rooty)
			edges.PB(MK(x+1,y+1));
		else
			un(parent,size,rootx,rooty);

	}
	REP(i,n)
		parent[i] = find(parent,parent[i]);
	// for(auto it: parent)
	// 	cout << it << " ";
	// cout << endl;
	set<ll> x;
	vector<ll> p;
	for(auto it: parent){
		if(x.find(it) != x.end())
			continue;
		p.PB(it);
		x.insert(it);
	}
	if(p.size()==1)
		cout << 0 << endl;
	else{
		ll pos=0;
		ll k = p.size()-1;
		cout << k << endl;
		ll start = p[0];
		ll curr=1;
		while(k--){
			cout << edges[pos].first << " " << edges[pos].second << " " << start+1 << " " << p[curr]+1 << endl;
			pos++;
			curr++;
		}
	}
	return 0;
}