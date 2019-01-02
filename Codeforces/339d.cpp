/*=======================
Author    : Shounak Dey
Filename  : 339d.cpp
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

#define MAXN 200010
vector<ll> segtree(MAXN<<2);
vector<ll> level(MAXN<<2);
vector<ll> arr(MAXN);

void build(ll pos,ll l,ll r){
	if(l==r){
		segtree[pos]=arr[l];
		level[pos]=0;
		return;
	}
	// error(l,r,pos);
	ll mid = (l+r)>>1;
	build(pos*2,l,mid);
	build(pos*2 + 1,mid+1,r);
	level[pos] = level[pos*2]+1;
	if(level[pos]&1)	
		segtree[pos] = segtree[pos*2] | segtree[pos*2 + 1];
	else
		segtree[pos] = segtree[pos*2] ^ segtree[pos*2 + 1];
	return;
}

void update(ll cpos,ll l,ll r,ll val, ll pos){
	if(l>pos || r<pos)
		return;
	if(l==r){
		segtree[cpos] = val;
		return;
	}
	// error(l,r,cpos,pos);
	ll mid = (l+r)>>1;
	update(cpos*2,l,mid,val,pos);
	update(cpos*2 + 1,mid+1,r,val,pos);
	if(level[cpos]&1)	
		segtree[cpos] = segtree[cpos*2] | segtree[cpos*2 + 1];
	else
		segtree[cpos] = segtree[cpos*2] ^ segtree[cpos*2 + 1];
	return;
}

int main()
{
	fast_io;
	ll n,q;
	cin >> n >> q;
	n = (1 << n);
	REP(i,n)
		cin >> arr[i];
	build(1,0,n-1);
	// for(auto it:segtree)
	// 	cout << it << " ";
	// cout << endl; 
	while(q--){
		ll p,x;
		cin >> p >> x;
		p--;
		update(1,0,n-1,x,p);
		// for(auto it: segtree)
		// 	cout << it << " ";
		// cout << endl;
		cout << segtree[1] << endl;
	}
	return 0;
}