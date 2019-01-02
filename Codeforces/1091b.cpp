/*=======================
Author    : Shounak Dey
Filename  : 1091b.cpp
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

typedef struct{
	ll x,y;
}point;

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<point> ob(n),cl(n);
	REP(i,n)
		cin >> ob[i].x >> ob[i].y;
	REP(i,n)
		cin >> cl[i].x >> cl[i].y;
	auto cmp = [](point a,point b){
		if(a.x==b.x)
			return a.y < b.y;
		return a.x < b.x;
	};
	set<point,decltype(cmp)> p(cmp);
	REP(i,n)
		p.insert(cl[i]);

	ll f=0;
	point ans;
	REP(i,n){
		point T = {ob[0].x + cl[i].x,ob[0].y + cl[i].y};
		// cout << T.x << " " << T.y << " " << ans.x << " " << ans.y << endl;
		p.erase(cl[i]);
		FOR(j,1,n){
			point tmp = {T.x - ob[j].x,T.y - ob[j].y};
			if(p.find(tmp)==p.end())
				break;
			p.erase(tmp);
		}
		if(p.size()==0)
			ans = T;
		REP(j,n)
			p.insert(cl[j]);
	} 
	cout << ans.x << " " << ans.y << endl;
	return 0;
}