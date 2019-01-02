/*=======================
Author    : Shounak Dey
Filename  : cf224.cpp
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

typedef struct {
	double x,y;
}point;

typedef struct {
	point a,b;
}line;

int main()
{
	fast_io;
	ll n;
	cin >> n;
	vector<pair<point,double>> angle(n);
	ll index=-1;
	double m=DBL_MAX,M=DBL_MIN;
	REP(i,n){
		cin >> angle[i].F.x >> angle[i].F.y;
		if(angle[i].F.y < m){
			index = i;
			m = angle[i].F.y;
		}
		else if(angle[i].F.y==m && angle[i].F.x<M)
			index = i;
	}
	angle[index].S = 0;

	auto get_angle = [](point a,point o){
		a.x -= o.x;
		a.y -= o.y;
		return atan2(a.y,a.x);
	};
	REP(i,n){
		if(index==i)
			continue;
		angle[i].S = get_angle(angle[i].F,angle[index].F);
	}
	sort(angle.begin(),angle.end(),[](pair<point,double> a,pair<point,double> b){
		return a.S < b.S;
	});
	FOR(i,1,n){
		
	}
	return 0;
}