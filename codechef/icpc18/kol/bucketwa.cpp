/*=======================
Author    : Shounak Dey
Filename  : bucketwa.cpp
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

int main()
{
	//The function of time over x ranging between 0 to dr is parabolic and hence has only one minima. 
	//Ternary search over the range to find the minima. Iterate 1000 times to converge to the answer.
	fast_io;
	double dl,dh,dr,k;
	cin >> dl >> dh >> dr >> k;
	auto check = [](double dl,double dh,double dr,double k){
		return !(dl==0 && dh==0 && dr==0 && k==0);
	};

	auto time = [](double dl,double dh,double dr,double k,double x){
		return sqrt(x*x + dl*dl) + k*sqrt((x-dr)*(x-dr) + dh*dh);
	};

	auto dist = [](double dl,double dh,double dr,double k,double x){
		return sqrt(x*x + dl*dl) + sqrt((x-dr)*(x-dr) + dh*dh);
	};	

	while(check(dl,dh,dr,k)){
		double xl=0,xr=dr;
		double mx1,mx2;
		REP(i,1000){
			mx1 = xl + (xr-xl)/3;
			mx2 = xr - (xr-xl)/3;
			double t1,t2;
			t1 = time(dl,dh,dr,k,mx1);
			t2 = time(dl,dh,dr,k,mx2);
			if(t1 > t2)
				xl = mx1;
			else
				xr = mx2;
		}
		cout << setprecision(15) << fixed;
		cout << dist(dl,dh,dr,k,xr) << endl;
		cin >> dl >> dh >> dr >> k;
	}
	return 0;
}