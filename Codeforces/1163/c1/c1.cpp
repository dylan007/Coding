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

typedef struct line{
	double m,c;

	bool operator<(const line& t) const{
		if(this->m == t.m)
			return (this->c < t.c);
		return this->m < t.m;
	};
}line;

int main()
{
	fast_io;
	int n;
	cin >> n;
	set<ll> infc;
	vector<pair<ll,ll>> p(n,pair<ll,ll>());
	REP(i,n)
		cin >> p[i].F >> p[i].S;
	set<line> x;
	REP(i,n){
		FOR(j,i+1,n){
			if(p[i].F == p[j].F)
				infc.insert(p[i].F);
			else{
				double m,c;
				m = (double)(p[i].S-p[j].S) / (double)(p[i].F-p[j].F);
				c = (double)(p[i].S) - m * (double)(p[i].F);
				line tmp = {m,c};
				x.insert(tmp);
			}
		}
	}
	int ans=0;
	vector<line> xt(x.begin(),x.end());
	REP(i,xt.size()){
		FOR(j,i+1,xt.size())
			ans += (xt[i].m != xt[j].m);
	}
	ans += (x.size() * infc.size());
	cout << ans << endl;
	return 0;
}

