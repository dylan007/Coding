/*=======================
Author    : Shounak Dey
Filename  : firesc.cpp
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

#define MOD ll(1e9+7)

ll find(vector<ll> &parent,ll x){
	if(x != parent[parent[x]])
		parent[x] = find(parent,parent[x]);
	return parent[x];
}

void un(vector<ll> &parent,vector<ll> &size,ll x,ll y){
	ll rootx = find(parent,x);
	ll rooty = find(parent,y);
	if(rootx != rooty){
		if(size[rootx]>size[rooty]){
			size[rootx] += size[rooty];
			parent[rooty] = rootx;
		}
		else{
			size[rooty] += size[rootx];
			parent[rootx] = rooty; 
		}
	}
	return;
}

int main()
{
	TEST{
		ll n,m;
		cin >> n >> m;
		vector<ll> parent(n),size(n);
		REP(i,n){
			parent[i] = i;
			size[i] =1;
		}
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			un(parent,size,x,y);
		}
		ll ans=1;
		map<ll,ll> count;
		for(auto it:parent){
			ll x = find(parent,it);
			if(count.find(x) == count.end())
				count[x] = size[x];
		}
		map<ll,ll>::iterator it = count.begin();
		int p=0;
		while(it != count.end()){
			ans = (ans * it->second)%MOD;
			p++;
			it++;
		}
		cout << p << " " << ans << endl;
	}
	return 0;
}