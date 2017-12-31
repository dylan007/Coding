/*=======================
Author    : Shounak Dey
Filename  : 908c.cpp
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


double calc(double p,double q)
{
	return sqrt(4*q*q - p*p);
}

int main()
{
	int n;
	double r;
	cin >> n >> r;
	vector<double> x(n);
	double m=0,M=INT_MAX;
	vector<pair<double,double>> points;
	REP(i,n)
	{
		cin >> x[i];
		m = max(m,x[i]);
		M = min(M,x[i]);
	}
	double shift = min(0.0,M-r);
	shift = fabs(shift);
	vector<int> flag((int)(m+r+shift) + 20,-1);
	//cout << shift << endl;
	REP(i,n)
		x[i] += shift;
	// for(auto it:x)
	// 	cout << it << " ";
	// cout << endl;
	REP(i,n)
	{
		if(i==0)
		{
			points.PB(MK(x[i],r));
			for(int j=x[i]-r;j<=x[i]+r)
				flag[j] = i;
		}
		else
		{
			int t=-1;
			//cout << x[i]-r << " " << x[i]+r << " " << flag.size() << endl; 
			for(int j=x[i]-r;j<=x[i]+r)
				t=max(t,flag[j]);
			// for(auto it: flag)
			// 	cout << it << " ";
			// cout << endl;
		//	cout << t << endl;
			if(t==-1)
			{
				points.PB(MK(x[i],r));
				for(int j=x[i]-r;j<=x[i]+r)
					flag[j] = i;
			}
			else
			{
				double px = fabs(x[i]-x[t]);
				double y = sqrt(4*r*r - px*px) + points[t].second;
				points.PB(MK(x[i],y));
				for(int j=x[i]-r;j<=x[i]+r)
					flag[j] = i;
			}
		}
	}
	cout << fixed;
	cout << setprecision(9);
	for(auto it:points)
		cout << it.second << " ";
	cout << endl;
	return 0;
}
