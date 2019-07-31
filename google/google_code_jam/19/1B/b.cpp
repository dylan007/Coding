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

int main()
{
	fast_io;
	int T;
	cin >> T;
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll p,q;
		cin >> p >> q;
		multiset<ll> s,w,n,e;
		vector<pair<ll,ll>> points;
		vector<char> dir;
		REP(i,p){
			ll x,y;
			char c;
			cin >> x >> y >> c;
			points.PB(MK(x,y));
			dir.PB(c);
		}
		pair<ll,ll> out = {LONG_MAX,LONG_MAX};
		ll res = LONG_MIN;
		FOR(i,0,q+1){
			FOR(j,0,q+1){
				ll c=0;
				REP(k,p){
					switch(dir[k]){
						case 'N':
							c += (j>points[k].S);
							break;
						case 'S':
							c += (j<points[k].S);
							break;
						case 'E':
							c += (i>points[k].F);
							break;
						case 'W':
							c += (i<points[k].F);
							break;
					}
				}
				if(res < c)
					out = {i,j};
				else if(res==c){
					if(out.F>i)
						out = {i,j};
					else if(out.S>j)
						out = {i,j};
				}
				res = max(res,c);
			}
		}
		cout << out.F << " " << out.S << endl;
	}
	return 0;
}

