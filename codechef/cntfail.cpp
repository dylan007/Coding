/*=======================
Author    : Shounak Dey
Filename  : cntfail.cpp
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

int main()
{
	fast_io;
	TEST{
		ll n;
		cin >> n;
		set<ll> p;
		map<ll,ll> c;
		REP(i,n){
			ll x;
			cin >> x;
			p.insert(x);
			if(c.find(x) != c.end())
				c[x]++;
			else
				c[x] = 1;
		}
		ll ans = -1;
		if(p.size()==1 && (((c.begin())->first)==(n-1) || ((c.begin())->first == 0))){
			if((c.begin())->first == 0)
				ans = 0;
			if((c.begin())->first == (n-1))
				ans = n;
		}
		if(p.size()==2){
			ll p1,p2;
			map<ll,ll>::iterator it = c.begin();
			ll v1,v2;
			p1 = it->second;
			v1 = it->first;
			it++;
			v2 = it->first;
			p2 = it->second;
			if(p1==(v1-1) && p2==v1)
				ans = n-v1;
			if(p1==v2 && p2==(v2-1))
				ans = n-v2; 
		}
		cout << ans << endl;
	}
	return 0;
}