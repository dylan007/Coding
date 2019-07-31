/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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

vector<ll> st,arr;

void build(ll l,ll r,ll pos){
	if(l==r)
		st[pos] = arr[l];
	else{
		ll mid = (l+r)/2;
		build(l,mid,2*pos);
		build(mid+1,r,2*pos+1);
		st[pos] = st[pos*2] + st[pos*2 + 1];
	}
	return;
}

ll query(ll l,ll r,ll pos,ll tl,ll tr){
	error(l,r);
	if(tl>tr)
		return 0;
	if((l==tl) && (r==tr))
		return st[pos];
	ll mid = (l+r)/2;
	return query(l,min(mid,r),2*pos,tl,mid) + query(max(l,mid+1),r,2*pos + 1,mid+1,tr);
}

int main()
{
	fast_io;
	ll n,q;
	cin >> n >> q;
	arr = vector<ll>(n);
	REP(i,n)
		cin >> arr[i];
	ll size = 4*n;
	st = vector<ll>(size,0);
	build(0,n-1,1);
	while(q--){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		cout << query(0,n-1,1,x,y) << endl;
	}
	return 0;
}

