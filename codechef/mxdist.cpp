/*=======================
Author    : Shounak Dey
Filename  : mxdist.cpp
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

#define MAXN 20010


// Define Point
typedef struct point{
	ll x,y;
}point;

vector<point> points(MAXN);

// Functions for point ds.
ll dist(point a,point b){
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

ll orient(point a,point b,point c){
	ll o = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	if(o!=0)
		return (o>0)?1:2;
	return 0;
}




vector<point> monotoneChain(ll start, ll end){
	vector<point> p;
	while(start<=end)
		p.PB(points[start++]);
	auto cmp = [](point a,point b){
		if(a.x==b.x)
			return a.y < b.y;
		return a.x < b.x;
	};
	sort(p.begin(),p.end(),cmp);
	ll k=0;
	if(p.size()<=3)
		return p;
	vector<point> hull(2*p.size());
	REP(i,p.size()){
		while(k>=2 && orient(hull[k-2],hull[k-1],p[i])!=2)
			k--;
		hull[k++] = p[i];
	}
	// REP(i,k)
		// cout << hull[i].x << " " << hull[i].y << endl;
	for(ll i=p.size()-1,lim=k+1;i>0;i--){
		while(k>=lim && orient(hull[k-2],hull[k-1],p[i-1])!=2)
			k--;
		hull[k++] = p[i-1];
	}
	hull.resize(k-1);
	return hull;
}


ll brutef(vector<point> hull){
	ll ans=0;
	REP(i,hull.size()){
		FOR(j,i+1,hull.size())
			ans = max(ans,dist(hull[i],hull[j]));
	}
	return ans;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	REP(i,n)
		cin >> points[i].x >> points[i].y;
	ll q,l,r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		l--;r--;
		vector<point> hull = monotoneChain(l,r);
		cout << brutef(hull) << endl;
	}
	return 0;
}