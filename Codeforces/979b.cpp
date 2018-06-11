/*=======================
Author    : Shounak Dey
Filename  : 979b.cpp
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

ll getmax(string a){
	map<char,ll> x;
	ll m=0;
	REP(i,a.length()){
		if(x.find(a[i])==x.end())
			x[a[i]] = 1;
		else
			x[a[i]]++;
		m = max(m,x[a[i]]);
	}
	return m;
}

int main()
{
	ll n;
	cin >> n;
	string a,b,c;
	cin >> a >> b >> c;
	ll x,y,z;
	x = getmax(a);
	y = getmax(b);
	z = getmax(c);
	ll l = l;
	// cout << x << " " << y << " " << z << endl;
	ll p = max(0ll,n-(l - x));
	x = min(l,n+x);
	if(x==l)
		x -= p%2;
	p = max(0ll,n-(l - y));
	y = min(l,n+y);
	if(y==l)
		y -= p%2;
	p = max(0ll,n-(l - z));
	z = min(l,n+z);
	if(z==l)
		z -= p%2;
	// cout << x << " " << y << " " << z << endl;
	if(x>max(y,z))
		cout << "Kuro" << endl;
	else if(y>max(x,z))
		cout << "Shiro" << endl;
	else if(z > max(x,y))
		cout << "Katie" << endl;
	else
		cout << "Draw" << endl;
	return 0;
}