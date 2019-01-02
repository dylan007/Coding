/*=======================
Author    : Shounak Dey
Filename  : mult3q.cpp
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

#define MAXN 300000

typedef struct{
	ll l,r,c0,c1,c2,lz;
}data;

vector<data> st(4*MAXN);

void init(ll pos=1,ll l=0,ll r=MAXN-1){
	data tmp;
	tmp.l = l;
	tmp.r = r;
	tmp.c0 = tmp.c1 = tmp.c2 = tmp.lz = 0;
	st[pos] = tmp;
	init(pos*2,l,(l+r)>>1);
	init(pos*2 + 1,((l+r)>>1)+1,r);
	return;
}

void push(ll pos){
	if(st[pos].lz){
				
	}
}

void update(ll pos=1,ll l,ll r){
	push(pos);
}

int main()
{
	fast_io;
	ll n,q;
	cin >> n >> q;
	vector<ll> arr(n,0);
	init();
	while(q--){
		ll c,l,r;
		cin >> c >> l >> r;
		l--;r--;
		if(c==0){
			update(l,r);
		}
	}
	return 0;
}