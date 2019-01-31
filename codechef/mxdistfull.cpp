/*=======================
Author    : Shounak Dey
Filename  : mxdistfull.cpp
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

class point{
public:
	ll x,y;

	point(ll x1=0,ll y1=0){
		x = x1;
		y = y1;
	}
	bool operator < (const point &b) const{
		return x<b.x || (x==b.x && y<b.y);
	}

	ll operator ^ (const point &b) const{
		return x * b.y - y * b.x;
	}

	point operator - (const point &b) const{
		return point(x-b.x,y-b.y);
	}

	ll dist(point a){
		return (a.x - x)*(a.x - x) + (a.y - y)*(a.y - y);
	}

	ll orient(point a, point b){
		ll tmp = (a.y-y)*(b.x-a.x) - (b.y-a.y)*(a.x-x);
		if(tmp==0) return 0;
		return (tmp>0)?1:2;			//1->Clockwise, 2->Counter Clockwise
	}	

	ll area(point b,point c){
		return (b.x - x)*(c.y - y) - (b.y - y) * (c.x - x); 
	}

	ll ccw(point a){
		return (*this) ^a;
	}
};


class hull{
public:
	vector<point> up,down;

	hull(){}

	hull(vector<point> a){
		up = a;
		down = a;
	}

	hull operator + (const hull &b) const{
		hull c;
		c.up.resize(up.size() + b.up.size());
		merge(up.begin(),up.end(),b.up.begin(),b.up.end(),c.up.begin());
		c.down.resize(down.size() + b.down.size());
		merge(down.begin(),down.end(),b.down.begin(),b.down.end(),c.down.begin());
		c.build();
		return c;
	}

	void build(){
		int n = up.size(),m=0;
		sort(up.begin(),up.end());
		sort(down.begin(),down.end());
		// vector<point> tup(n),tdown(down.size());
		REP(i,n){
			while(m>1 && up[i].orient(up[m-1],up[m-2])!=1)
				m--;
			up[m++] = up[i];
		}
		up.resize(m);
		n = down.size();m=0;
		REP(i,n){
			while(m>1 && down[i].orient(down[m-1],down[m-2])!=2)
				m--;
			down[m++] = down[i];
		}
		down.resize(m);
	}

	void print(){
		for(auto it: up) 
			cout << it.x << " " << it.y << endl;
		for(auto it: down)
			cout << it.x << " " << it.y << endl;
	}

	ll solve(){
		ll ans=0;
		vector<point> h = up;
		for(ll i=down.size()-2;i>0;i--)
			h.PB(down[i]);
		REP(i,h.size()){
			FOR(j,i+1,h.size())
				ans = max(ans,h[i].dist(h[j]));
		}
		return ans;
	}

	ll calipers(){
		ll ans=0;
		vector<point> h = up;
		ll m = h.size();
		for(ll i=down.size()-2;i>0;i--)
			h.PB(down[i]);	
		if(h.size()==1)
			return 0;
		if(h.size()==2)
			return h[0].dist(h[1]);
		for(ll i=0,j=1;i<h.size();i++){
			while(h[i].dist(h[(j+1)%h.size()]) > h[i].dist(h[j]))
				j = (j+1)%m;
			ans = max(ans,h[i].dist(h[j]));
			ans = max(ans,h[(i+1)%h.size()].dist(h[(j+1)%h.size()]));
		}
		return ans;
	}

	ll calipers2(){
		ll ans=0;
		vector<point> h = up;
		for(ll i=down.size()-2;i>0;i--)
			h.PB(down[i]);
		ll n = h.size();
		for(ll i=0,j=(n<2?0:1);i<j;i++){
			for(;;j = (j+1)%n){
				ans = max(ans,h[i].dist(h[j]));
				if((h[i+1]-h[i]).ccw(h[(j+1)%n]-h[j]) >= 0) break;
			}
		}
		return ans;
	}
};

#define MAXN 200100
vector<hull> st;
vector<point> points;
hull ret;
ll l,r;
ll getSize(ll n){
	ll mx = 1;
	while(mx < n) mx<<=1;
	return mx<<1;
}


void build(ll pos,ll start,ll end){
	// error(pos,start,end);
	if(start == end)
		st[pos] = hull({points[start]});
	else{
		ll mid = (start + end)>>1;
		build(pos*2,start,mid);
		build(2*pos + 1,mid+1,end);
		st[pos] = st[2*pos] + st[2*pos + 1];
	}
	return;
}

void query(ll pos,ll start,ll end){
	if(start>r || end<l || end<start) return;
	if(start>=l && end<=r){
		ret = ret + st[pos];
		return;
	}
	ll mid = (start+end)>>1;
	// error(pos,start,end,l,r,mid);
	// cout << endl;
	query(2*pos,start,mid);
	query(2*pos + 1,mid+1,end);
	return;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	REP(i,n){
		ll x,y;
		cin >> x >> y;
		points.PB(point(x,y));
	}
	st.resize(getSize(n));
	build(1,0,n-1);
	// cout << "Built tree of hulls" << endl;
	ll q;
	cin >> q;
	while(q--){
		cin >> l >> r;
		l--;r--;
		ret = hull();
		query(1,0,n-1);
		cout << ret.calipers2() << endl;
	}
	return 0;
}