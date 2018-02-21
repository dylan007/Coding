/*=======================
Author    : Shounak Dey
Filename  : 935c.cpp
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

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double calc(pair<double,double> p,double x,double y,double r){
	if((x*x + y*y) > r*r)
		return -1;
	return dist(x,y,p.first,p.second)/2;
}

int main()
{
	double r,x1,y1,x2,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	double temp1,temp2;
	temp1 = x1;
	temp2 = y1;
	x1=0;
	y1=0;
	x2 -= temp1;
	y2 -= temp2;
	double m;
	if(x1!=x2 && ((x2*x2 + y2*y2 <= r*r))){
		m = (y2-y1)/(x2-x1);
		double k1 = y1-m*x1;
		double k2 = m;
		double d = (4*k1*k1*k2*k2) - 4*(1+k2*k2)*(k1*k1 - r*r);
		d = sqrt(d);
		double p1 = (0-(2*k1*k2)-d)/(2*(1+k2*k2));
		double p2 = (0-(2*k1*k2)+d)/(2*(1+k2*k2));
		double q1,q2;
		q1 = sqrt(r*r - p1*p1);
		q2 = sqrt(r*r - p2*p2);
		vector<pair<double,double>> points;
		points.PB(MK(p1,q1));
		points.PB(MK(p1,0-q1));
		points.PB(MK(p2,q2));
		points.PB(MK(p2,0-q2));
		vector<double> radii;
		REP(i,4)
			radii.PB(calc(points[i],x2,y2,r));
		double max=0;
		int index=-1;
		REP(i,4){
			//cout << radii[i] << endl;
			//cout << points[i].first << " " << points[i].second << endl;
			if(max<radii[i]){
				max = radii[i];
				index = i;
			}
		}
		cout << setprecision(9) << fixed;
		cout << (points[index].first+x2)/2+temp1 << " " << (points[index].second+y2)/2+temp2  << " " << max << endl;
	}
	else if((x2*x2 + y2*y2) <= r*r){
		double p1,p2;
		p1 = r;
		p2 = 0-r;
		vector<pair<double,double>> points;
		points.PB(MK(x1,p1));
		points.PB(MK(x1,p2));
		vector<double> radii;
		REP(i,2)
			radii.PB(calc(points[i],x2,y2,r));
		double max=0;
		int index=-1;
		REP(i,2){
			if(max<radii[i]){
				max = radii[i];
				index = i;
			}
		}
		cout << setprecision(9) << fixed;
		cout << (points[index].first+x2)/2+temp1 << " " << (points[index].second+y2)/2+temp2  << " " << max << endl;
	}
	else{
		cout << setprecision(9) << fixed;
	//	cout << "alkn" << endl;
		cout << x1+temp1 << " " << y1+temp2 << " "  << r << endl;
	}
	return 0;
}
