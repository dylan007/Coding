/*=======================
Author    : Shounak Dey
Filename  : infi1802.cpp
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

#define LIM 1000000
#define MOD 1000000007

int main()
{
	vector<int> val(LIM+1,0);
	vector<int> primes(LIM+1,0);
	FOR(i,2,LIM+1){
		if(primes[i]==0){
			val[i] = i;
			for(int j=2*i;j<=LIM;j+=i){
				primes[j] = 1;
				val[j] = (val[j]+i)%MOD;
			}
		}
	}
	FOR(i,1,LIM+1)
		val[i] = (val[i]+val[i-1])%MOD;
	TEST{
		int x,y;
		cin >> x >> y;
		x--;
		cout << (MOD + val[y]-val[x])%MOD << endl;
	}
	return 0;
}