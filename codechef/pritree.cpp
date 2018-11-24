/*=======================
Author    : Shounak Dey
Filename  : pritree.cpp
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

void sieve(vector<ll> &primes){
	primes = vector<ll>(20001,0);
	primes[0]=primes[1] = 1;
	FOR(i,2,primes.size()){
		if(primes[i]==0){
			primes[i] = 0;
			for(int j=2*i;j<primes.size();j+=i)
				primes[j] = 1;
		}
	}
	return;
}

int main()
{
	fast_io;
	ll n;
	cin >> n;
	ll x;
	vector<ll> primes;
	sieve(primes);
	vector<ll> p,c;
	REP(i,n){
		cin >> x;
		if(primes[x]==0)
			p.PB(i+1);
		else
			c.PB(i+1);
	}
	if(p.size()==0){
		REP(i,c.size()-1)
			cout << c[i] << " " << c[i+1] << endl;
		return 0;
	}
	// ll root = p[0];
	// FOR(i,1,p.size())
	// 	cout << root << " " << p[i] << endl;
	// if(c.size()>0){
	// 	cout << root << " " << c[0] << endl;
	// 	REP(i,c.size()-1)
	// 		cout << c[i] << " " << c[i+1] << endl;
	// }
	if(c.size()>0){
		ll root = c[0];
		REP(i,p.size())
			cout << root << " " << p[i] << endl;
		REP(i,c.size()-1)
			cout << c[i] << " " << c[i+1] << endl;
	}
	else{
		ll root = p[0];
		FOR(i,1,p.size())
			cout << root << " " << p[i] << endl;
	}
	return 0;
}