/*=======================
Author    : Shounak Dey
Filename  : beenums.cpp
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

ll exp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans *= a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

int binsearch(ll start,ll end,ll x){
	ll mid = (start + end)/2;
	ll l,r;
	if(mid>1)
		l = 1 + ((mid-1) * (2*6 + (mid-2)*6))/2;
	else
		l = 1;
	r = 1 + (mid * (2*6 + (mid-1)*6))/2;
	// error(mid,l,r);
	if(start>end)
		return 0;
	if(l<x && r>x)
		return 0;
	if(l==x || r==x)
		return 1;
	if(l>x)
		return binsearch(start,mid-1,x);
	return binsearch(mid+1,end,x);
}

int main()
{
	fast_io;
	ll x;
	cin >> x;
	while(x!=-1){
		if(binsearch(1,(ll)1e5,x))
			cout << "Y" << endl;
		else
			cout << "N" << endl;
		cin >> x;
	}
	return 0;
}