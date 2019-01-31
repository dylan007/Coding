/*=======================
Author    : Shounak Dey
Filename  : xypizq.cpp
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

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

int main()
{
	fast_io;
	TEST{
		ll N,t,x,y,z;
		cin >> N >> t >> x >> y >> z;
		ll denum = 2*N + 1;
		ll num;
		if(t==1){
			if(x<y && y>z)
				num = z;
			else if(x<y && y<z)
				num = denum - z;
			else if(x>y && y<z)
				num = z;
			else
				num = denum - z;
		}
		else if(t==2 || t==4)
			num = denum - 2*y;
		else{
			ll x1=z,y1=y,z1=x;
			x = x1;
			y = y1;
			z = z1;
			if(x<y && y>z)
				num = z;
			else if(x<y && y<z)
				num = denum - z;
			else if(x>y && y<z)
				num = z;
			else
				num = denum - z;
		}
		ll g = gcd(num,denum);
		cout << num/g << " " << denum/g << endl;
	}	 
	return 0;
}