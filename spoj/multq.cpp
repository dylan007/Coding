/*=======================
Author    : Shounak Dey
Filename  : multq.cpp
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

void update(ll pos,vector<ll> &st,vector<ll> &lz,ll l,ll r,ll start,ll end){
	if(lz[pos]!=0){
		st[pos] = (end-start+1)*lz[pos];
		lz[pos*2] += lz[pos];
		lz[pos*2 + 1] += lz[pos];
		lz[pos] = 0;
	}
	if(start>end || start>r || end<l)
		return;
	if(start>=l && end<=r){
		st[pos] += (end-start+1);
		if(start!=end){
			lz[pos*2]++;
			lz[pos*2 + 1]++; 
		}
		return;
	}
	ll mid = (start+end)>>1;
	update(2*pos,st,lz,l,r,start,mid);
	update(2*pos+1,st,lz,l,r,mid+1,end);
	st[pos] = st[pos*2] + st[pos*2 + 1];
	return;
}

ll query(ll pos,vector<ll> &st,vector<ll> &lz,ll l,ll r,ll start,ll end){

}

int main()
{
	fast_io;
	ll n,q;
	cin >> n >> q;
	vector<ll> arr(n,0);
	vector<ll> st(4*n+10,0);
	vector<ll> lz(4*n+10,0);
	while(q--){
		ll c,a,b;
		cin >> c >> a >> b;
		if(!c)
			update(1,st,lz,a,b,0,n-1);
		else
			cout << query(1,st,lz,a,b,0,n-1) << endl;
	}
	return 0;
}