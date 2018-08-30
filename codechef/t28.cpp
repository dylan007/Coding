/*=======================
Author    : Shounak Dey
Filename  : t28.cpp
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

#define MOD 1000000009

ull modinv(ull x){
	ull p = MOD-2;
	ull ans=1;
	while(p){
		if(p&1)
			ans = (ans*x)%MOD;
		x = (x*x)%MOD;
		p >>= 1;
	}
	return ans;
}

int main()
{
	ull n,k;
	cin >> n >> k;
	map<ull,ull> c;
	while(n--){
		ull x,y;
		cin >> x >> y;
		x = 4*x*y + 2*max(x,y);
		if(c.find(x)!=c.end())
			c[x]++;
		else
			c[x] = 1;
	}
	while(k--){
		ull x;
		cin >> x;
		x = x*(x+1);
		if(c.find(x)!=c.end())
			cout << modinv(c[x]) << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}