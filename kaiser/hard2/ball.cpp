/*=======================
Author    : Shounak Dey
Filename  : 203d.cpp
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

void solve(double a,double b,double m,double vx,double vy,double vz)
{
	double x,y,z;
	cout << fixed << setprecision(9);
	y = m;
	x = a/2;
	z = 0;
	double sx,ex,sy,ey,sz,ez;
	sx = 0;
	ex = a;
	sy = 0;
	ey = m;
	sz = 0;
	ez = b;
	while(y>0)
	{
		//cout << x << " " << y << " " << z << endl;
		double tx,ty,tz;
		double dx,dy,dz;
		if(vx>=0)
			dx = ex-x;
		else
			dx = x-sx;
		if(vy>=0)
			dy = ey-y;
		else
			dy = y-sy;
		if(vz>=0)
			dz = ez-z;
		else
			dz = z-sz;
		//cout << dx << " " << dy << " " << dz << endl;
		tx = dx/vx;
		ty = dy/vy;
		tz = dz/vz;
		tx = (tx>0)?tx:(0-tx);
		ty = (ty>0)?ty:(0-ty);
		tz = (tz>0)?tz:(0-tz);
		//cout << tx << " " << ty << " " << tz << endl; 
		double t = (tx>ty?ty:tx)>tz?tz:(tx>ty?ty:tx);
		// if(t<0)
		// 	t = 0-t;
		dx = t*vx;
		dy = t*vy;
		dz = t*vz;
		dx = (dx>0)?dx:(0-dx);
		dy = (dy>0)?dy:(0-dy);
		dz = (dz>0)?dz:(0-dz);
		//cout << dx << " " << dy << " " << dz << endl;
		if(vx>=0)
			x += dx;
		else
			x -= dx;
		if(vy>=0)
			y += dy;
		else
			y -= dy;
		if(vz>=0)
			z += dz;
		else
			z -= dz;
		if(t == tx)
			vx = 0-vx;
		else if(t==ty)
			vy = 0-vy;
		else if(t==tz)
			vz = 0-vz;
		//cout << vx << " " << vy << " " << vz << endl;
		//cout << x << " " << y << " " << z << endl;
	}	
	cout << x << " " << z << endl;
}

int main()
{
	double a,b,m;
	double vx,vy,vz;
	cin >> a >> b >> m >> vx >> vy >> vz;
	solve(a,b,m,vx,vy,vz);
	return 0;
}
