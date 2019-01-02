/*=======================
Author    : Shounak Dey
Filename  : 356a.cpp
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

#define MAX 300010

vector<ll> w(MAX),st(4*MAX,0),lz(4*MAX,0);

void commit(ll pos,ll start,ll end){
	if(lz[pos]){
		lz[pos*2] = lz[pos*2 + 1] = lz[pos];
		if(start == end)
			w[start] = lz[pos];
		commit(pos*2,start,(start+end)>>1);
		commit(pos*2 + 1,((start+end)>>1)+1,end);
	}	
	return;
}

void update(ll pos,ll l,ll r,ll start, ll end, ll val){
	if(start>end)
		return;
	commit(pos,start,end);
	error(pos,start,end);
	if(start==end){
		w[pos] = val;
		return;
	}
	if(start==l && end==r){
		lz[pos] = val;
		return;
	}
	else{
		ll mid = (start+end)>>1;
		update(pos*2,l,r,start,mid,val);
		update(pos*2,l,r,mid+1,end,val);
	}
}

int main()
{
	fast_io;
	ll n,k;
	cin >> n >> k;
	vector<ll> w(n,0);
	vector<ll> st(4*n,0);
	vector<ll> lz(4*n,0);
	while(k--){
		ll l,r,x;
		cin >> l >> r >> x;
		l--;r--;x--;
		if(x>l)
			update(1,l,x-1,0,n-1,x);
		if(x<r)
			update(1,x+1,r,0,n-1,x);
	}
	REP(i,n)
		cout << w[i] << " ";
	cout << endl;
	return 0;
}