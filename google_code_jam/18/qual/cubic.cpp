/*=======================
Author    : Shounak Dey
Filename  : cubic.cpp
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

#define root2 1.414213

int main()
{
	int T;
	cin >> T;
	for(int test=1;test<=T;test++){
		cout << "Case #" << test << ": " << endl;
		double x;
		cin >> x;
		if(x<=root2){
			double sin,cos;
			sin = x*x-1;
			cos = sqrt(1-sin*sin);
			sin = sqrt((1-cos)/2);
			cos = sqrt((1+cos)/2);
			cout << setprecision(8) << fixed;
			cout << cos/2 << " " << sin/2 << " " << 0 << endl;
			cout << 0-(sin/2) << " " << cos/2 << " " << 0 << endl;
			cout << 0 << " " << 0 << " " << 0.5 << endl; 
		}
		else{
			double ix,iy,iz,sin,cos;
			sin = root2*root2-1;
			cos = sqrt(1-sin*sin);
			sin = sqrt((1-cos)/2);
			cos = sqrt((1+cos)/2);
			ix = cos/2;
			iy = sin/2;
			iz = 0;
			double sinal,cosal;
			cosal = sqrt(1-((x*x)/2-1)*((x*x)/2 - 1));
			sinal = sqrt((1-cosal)/2);
			cosal = sqrt((1+cosal)/2);
			double x,y,z;
			x = ix;
			y = iy*cosal - iz*sinal;
			z = iy*sinal + iz*cosal;
			cout << x << " " << y << " " << z << endl;
			ix = 0-sin/2;
			iy = cos/2;
			iz = 0;
			x = ix;
			y = iy*cosal - iz*sinal;
			z = iy*sinal + iz*cosal;
			cout << x << " " << y << " " << z << endl;
			ix = 0;
			iy = 0;
			iz = 0.5;
			x = ix;
			y = iy*cosal - iz*sinal;
			z = iy*sinal + iz*cosal;
			cout << x << " " << y << " " << z << endl;
		}	
	}
	return 0;
}
