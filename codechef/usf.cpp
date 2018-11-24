/*=======================
Author    : Shounak Dey
Filename  : usf.cpp
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

#define LIM 100100

int main()
{
	vector<ll> flag(LIM+1,0);
	vector<ll> primes;
	vector<ll> count(LIM+1,0);
	FOR(i,2,LIM+1){
		if(flag[i]==0){
			for(ll j=2*i;j<=LIM;j+=i){
				count[j]++;
				flag[j]=1;
			}
			primes.PB(i);
			count[i] = 1;
		}
	}
	vector<vector<ll>> div(LIM+1,vector<ll>());
	FOR(i,2,LIM+1){
		ll curr=2;
		if(flag[i]==0){
			div[i].PB(i);
			continue;
		}
		div[i].PB(i);
		while(curr*curr <= i){
			if((i%curr) == 0)
				div[i].PB(curr);
			curr++;
		}
	}
	ll ans=0;
	ll i=1;
	TEST{
		ll n;
		cin >> n;
		ll p;
		vector<ll> x(LIM,0);
		ll ans=0;
		while(n--){
			ll p;
			cin >> p;	
			// cout << div[p].size() << endl;
			for(auto it:div[p]){
				// cout << it << " ";
				x[it]++;
				ll q = p/it;
				ans = max(count[it]*x[it],ans);
				if(q==it)
					continue;
				x[q]++;
				ans = max(count[q]*x[q],ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}