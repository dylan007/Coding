/*=======================
Author    : Shounak Dey
Filename  : ncc1803.cpp
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

void sieve(vector<int> &primes)
{
	FOR(i,2,100001)
	{
		if(primes[i] == 0){
			for(int j=2*i;j<100001;j+=i)
				primes[j] = 1;
		}
	}
}

int main()
{
	vector<int> primes(100001,0);
	sieve(primes);
	TEST{
		int n;
		cin >> n;
		map<int,int> c;
		REP(i,n){
			int x;
			cin >> x;
			if(!primes[x])
			{
				if(c.find(x)==c.end())
					c[x] = 1;
				else
					c[x]++;
			}
		}
		map<int,int>::iterator it;
		it = c.begin();
		int ans=0;
		while(it != c.end()){
			//cout << it->first << " " << it->second << endl;
			ans += (it->second)/2;
			it++;
		}
		// cout << ans << endl;
		if(ans%2 == 0)
			cout << "Shivam" << endl;
		else
			cout << "Sagar" << endl;
	}
	return 0;
}
