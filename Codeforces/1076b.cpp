/*=======================
Author    : Shounak Dey
Filename  : 1076b.cpp
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

#define LIM 1000000

void sieve(vector<ll> &primes){
	vector<ll> flag(LIM+1,0);
	flag[0] = flag[1] = 1;
	FOR(i,2,LIM+1){
		if(flag[i])
			continue;
		for(int j=2*i;j<=LIM;j+=i)
			flag[j] = 1;
		primes.PB(i);
	}
	return;
}

int isPrime(ll x,vector<ll> primes){
	for(auto it:primes){
		if((x % it)==0)
			return 0;
	}
	return 1;
}

int main()
{
	fast_io;
	vector<ll> primes;
	sieve(primes);
	ll x;
	cin >> x;
	ll m = -1;
	if(isPrime(x,primes))
		cout << 1 << endl;
	else if(x&1){
		for(auto it: primes){
			if((x%it)==0){
				m = it;
				break;
			}
		}
		x -= m;
		cout << x/2 + 1 << endl;
	}
	else
		cout << x/2 << endl;
	return 0;
}