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

void un(vector<ll> &parent,vector<ll> &size,ll x,ll y){
	ll rootx = find(parent,x);
	ll rooty = find(parent,y);
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
	vector<ll> parent(n),size(n,1);
	REP(i,n)
		parent[i] = i;
	REP(i,m){
		ll x,y;
		readl(x);readl(y);
		x--;y--;
		un(parent,size,x,y);
	}
	// for(auto it:parent)
	// 	cout << it << " ";
	// cout << endl;
	vector<ll> val(n);
	REP(i,n)
		readl(val[i]);
	map<ll,ll> count;
	ll tot=0,c=0;
	REP(i,n){
		if(count.find(parent[i]) != count.end()){
			if(val[i]>=0)
				count[parent[i]] = min(count[parent[i]],val[i]);
		}
		else{
			if(val[i]>=0){
				c++;
				count[parent[i]] = val[i];
			}
			tot++;
		}
	}
	vector<ll> cities;
	if(tot != c)
		cout << -1 << endl;
	else{
		ll ans=0;
		map<ll,ll>::iterator it = count.begin();
		while(it != count.end()){
			cities.PB(it->second);
			it++;
		}
		SORTV(cities);
		if(cities.size() == 1)
			cout << 0 << endl;
		else if(cities.size()==2)
			cout << cities[0] + cities[1] << endl;
		else{
			for(auto it:cities)
				ans += 2*it;
			cout << ans - cities[cities.size()-1] - cities[cities.size()-2] << endl;
		}
	}
	return 0;
}