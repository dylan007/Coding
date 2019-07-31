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

#define LIM 100000

int main()
{
	fast_io;
	TEST{
		ll n;
		ll l,r,u,d;
		ll f=0;
		ll x,y,fl,fu,fr,fd;
		l = 0-LIM;
		r = LIM;
		u = LIM;
		d = 0-LIM;
		cin >> n;
		REP(i,n){
			cin >> x >> y >> fl >> fu >> fr >> fd;
			if(f)
				continue;
			ll xl=0-LIM;
			ll xr=LIM;
			if(!fl)
				xl = x;
			if(!fr)
				xr = x;
			if((xr<l) || (r<xl)){
				f=1;
				continue;
			}
			l = max(xl,l);
			r = min(xr,r);
			ll yd=0-LIM;
			ll yu=LIM;
			if(!fu)
				yu = y;
			if(!fd)
				yd = y;
			if((yu<d) || (u<yd)){
				f=1;
				continue;
			}
			d = max(yd,d);
			u = min(yu,u);
		}
		if(f)
			cout << 0 << endl;
		else
			cout << 1 << " " << l << " " <<  u << endl;
	}
	return 0;
}

