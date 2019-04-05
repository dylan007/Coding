/*=======================
Author    : Shounak Dey
Filename  : 1133d.cpp
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

typedef struct frac{
	ll n,d;
}frac;

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<frac> x(n);
	REP(i,n)
		cin >> x[i].d;
	REP(i,n)
		cin >> x[i].n;
	REP(i,n)
		x[i].n = 0-x[i].n;
	map<double,ll> c;
	ll aux=0;
	REP(i,n){
		if(x[i].d==0){
			aux += (x[i].n==0);
			continue;
		}
		else if(x[i].n==0)
			c[0.0]++;
		else{
			ll g = __gcd(x[i].n,x[i].d);
			x[i].n /= g;
			x[i].d /= g;
			double p = (double)x[i].n / (double)x[i].d;
			c[p]++;
		}
	}
	ll ans=0;
	for(auto it: c){
		error(it.first,it.second);
		ans = max(ans,it.second);
	}
	cout << ans+aux << endl;
	return 0;
}