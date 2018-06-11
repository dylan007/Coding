/*=======================
Author    : Shounak Dey
Filename  : workways.cpp
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

#define lim 1000000

void sieve(vector<int> &primes){
	vector<int> flag(lim,0);
	FOR(i,2,lim){
		if(!flag[i]){
			primes.PB(i);
			for(int j=2*i;j<lim;j+=i)
				flag[j] = 1;
		}
	}
	return;
}

int main()
{
	vector<int> primes;
	sieve(primes);
	TEST{
		int n,c;
		cin >> n >> c;
		vector<int> factors;
		int curr=0;
		while(curr < primes.size()){
			if(primes[curr]>c)
				break;
			if(c%primes[curr])
				curr++;
			else{
				while((c%primes[curr]) == 0){
					// error(factors.size(),c,curr);
					if(factors.size() == (n-1))
						factors.PB(c);
					else
						factors.PB(primes[curr]);
					if(factors.size()==n)
						break;
					c /= primes[curr];
				}
				curr++;
			}
			if(factors.size()==n)
				break;
		}
		if(factors.size()<n){
			while(factors.size()<n)
				factors.PB(1);
		}
		sort(factors.rbegin(),factors.rend());
		REP(i,n)
			cout << factors[i]+(n-i-1) << " ";
		cout << endl;
	}
	return 0;
}