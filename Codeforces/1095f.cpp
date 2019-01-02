/*=======================
Author    : Shounak Dey
Filename  : 1095f.cpp
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

typedef struct edge{
	ll x,y,w;
	edge(ll a,ll b,ll c){
		x = a;
		y = b;
		w = c;
	}
}edge;

ll find(vector<ll> &parent,ll x){
	if(parent[x]!=x)
		parent[x] = find(parent,parent[x]);
	return parent[x];
}

int main()
{
	fast_io;
	ll n,k;
	cin >> n >> k;
	vector<pair<ll,ll>> arr(n);
	REP(i,n){
		cin >> arr[i].F;
		arr[i].S = i;
	}
	sort(arr.begin(),arr.end(),[](auto a,auto b){
		return a.F < b.F;
	});
	vector<edge> l;
	FOR(i,1,n)
		l.PB(edge(arr[0].S,arr[i].S,arr[i].F + arr[0].F));
	REP(i,k){
		ll x,y,w;
		cin >> x >> y >> w;
		x--;y--;
		l.PB(edge(x,y,w));
	}
	sort(l.begin(),l.end(),[](auto a,auto b){
		return a.w < b.w;
	});
	// for(auto it: l)
	// 	cout << it.x << " " << it.y << " " << it.w << endl;
	vector<ll> fin(n,0);
	ll cost=0,pos=0;
	vector<ll> parent(n,0),size(n,1);
	REP(i,n)
		parent[i] = i;
	while(pos<l.size()){
		ll rootx = find(parent,l[pos].x);
		ll rooty = find(parent,l[pos].y);
		if(rootx == rooty){
			pos++;
			continue;
		}
		// cout << l[pos].x << " " << l[pos].y << " " << l[pos].w << endl;
		cost += l[pos].w;
		if(size[rootx]>size[rooty]){
			parent[rooty] = rootx;
			size[rootx] += size[rooty]; 
		}
		else{
			parent[rootx] = rooty;
			size[rooty] += size[rootx];
		}
		pos++;
	}
	cout << cost << endl;
	return 0;
}