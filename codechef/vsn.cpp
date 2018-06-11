/*=======================
Author    : Shounak Dey
Filename  : vsn.cpp
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
#define popc(a) __ builtin_popcount(a) // count set bits
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

typedef struct point{
	double x,y,z;
}point;

double dot(point a,point b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

point scalarmul(point a,double k){
	point p;
	p.x = a.x * k;
	p.y = a.y * k;
	p.z = a.z * k;
	return p;
}

point diff(point a,point b){
	point p;
	p.x = b.x - a.x;
	p.y = b.y - a.y;
	p.z = b.z - a.z;
	return p;
}

point add(point a,point b){
	point p;
	p.x = b.x + a.x;
	p.y = b.y + a.y;
	p.z = b.z + a.z;
	return p;	
}

point projection(point a,point b,point p){
	point out;
	double ratio = dot(diff(a,p),diff(b,a))/dot(diff(b,a),diff(b,a));
	out = scalarmul(diff(b,a),ratio);
	out = add(out,a);
	return out;
}

point cross(point a,point b){
	point c;
	c.x = a.y*b.z - a.z*b.y;
	c.y = -(a.x*b.z - a.z*b.x);
	c.z = a.x*b.y - a.y*b.x;
	return c;
}

void disp(point a){
	cout << a.x << " " << a.y << " " << a.z << endl;
}

double dist(point a,point b){
	return sqrt(dot(diff(a,b),diff(a,b)));
}

double solve(double m,double n,double o){
	if(m==0)
		return (0-o)/n;
	double d = n*n - 4*o*m;
	d = sqrt(d);
	double r1,r2;
	r1 = (d - n)/(2*m);
	r2 = (-d - n)/(2*m);
	return max(r1,r2);
}

int main()
{
	TEST{
		point p,q,c,d;
		double r;
		cin >> p.x >> p.y >> p.z >> q.x >> q.y >> q.z >> d.x >> d.y >> d.z >> c.x >> c.y >> c.z >> r;
		p = diff(q,p);
		c = diff(q,c);
		q = diff(q,q);
		// disp(p);
		// disp(q);
		// disp(c);
		// disp(d);
		// point k = diff(c,p);
		// double l = dot(k,d);
		// double m,n,o;
		// m = l*l*(dot(d,d));
		// n = 0- 2*l*dot(k,d);
		// o = dot(k,k) - r*r;
		// error(m,n,o);
		point a,b;
		a = cross(c,p);
		b = add(cross(c,d),cross(d,p));
		double m,n,o;
		// disp(a);
		// disp(b);
		m = dot(b,b) - r*r*dot(d,d);
		n = 0-(2*dot(a,b) - 2*r*r*dot(p,d));
		o = dot(a,a) - r*r*dot(p,p);
		// error(m,n,o);
		double ans = solve(m,n,o);
		cout << setprecision(9) << fixed;
		cout << ans << endl;
	}
	return 0;
}
