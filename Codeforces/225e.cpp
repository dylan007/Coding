/*=======================
Author    : Shounak Dey
Filename  : 225e.cpp
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

#define MOD 1000000007

ull powermod(ull x,ull p)
{
	ull ans=1;
	while(p)
	{
		if(p&1)
			ans = (ans*x)%MOD;
		x = (x*x)%MOD;
		p >>= 1;
	}
	return ans;
}

int main()
{
	ull n;
	cin >> n;
	vector<ull> uns = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,
 2203,2281,3217,4253,4423,9689,9941,11213,19937,
 21701,23209,44497,86243,110503,132049,216091,
 756839,859433,1257787,1398269,2976221,3021377,
 6972593,13466917,20996011,24036583,25964951,
 30402457,32582657,37156667};
 	ull ans=1;
 	REP(i,uns[n-1]-1)
 	{
 		ans *= 2;
 		ans %= MOD;
 	}
 	cout << (ans + MOD - 1)%MOD << endl;
	return 0;
}
