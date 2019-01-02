/*=======================
Author    : Shounak Dey
Filename  : rmqsq.cpp
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

#define MAX 100000

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<ll> lg(MAX+1,0);
	FOR(i,1,MAX+1)
		lg[i] = lg[i/2]+1;
	vector<ll> arr(n);
	REP(i,n)
		cin >> arr[i];
	vector<vector<ll>> st(n,vector<ll>(lg[MAX],0));
	REP(i,n)
		st[i][0] = arr[i];
	FOR(j,1,lg[MAX]+1){
		for(ll i=0;(i + (1 << j))<=n;i++){
			st[i][j] = min(st[i][j-1],st[i + (1 << (j-1))][j-1]);
		}
	}
	// for(auto it: st){
	// 	for(auto its:it)
	// 		cout << its << " ";
	// 	cout << endl;
	// }
	ll q;
	cin >> q;
	while(q--){
		ll x,y;
		cin >> x >> y;
		ll j = lg[y-x+1]-1;
		// error(x,y,j);
		cout << min(st[x][j],st[y-(1<<j)+1][j]) << endl;
	}
	return 0;
}