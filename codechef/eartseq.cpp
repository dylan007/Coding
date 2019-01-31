/*=======================
Author    : Shounak Dey
Filename  : eartseq.cpp
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

#define MAXN 300000

int main()
{
	fast_io;
	vector<ll> primes;
	vector<ll> flag(MAXN,0);
	FOR(i,2,MAXN){
		if(flag[i]==0){
			primes.PB(i);
			for(ll j=2*i;j<MAXN;j+=i)
				flag[j] = 1;				
		}
	}
	// cout << 5000 << endl;
	TEST{
		ll n;
		cin >> n;
		// cout << n << endl;
		if(n&1){
			vector<ll> ans;
			ll curr=3;
			n--;
			ll tmp = n>>1;
			ll f=0;
			while(ans.size()<n){
				if(!f){
					ans.PB(2*primes[curr]);
					ans.PB(3*primes[curr]);
				}
				else{
					ans.PB(3*primes[curr]);
					ans.PB(2*primes[curr]);
				}
				f ^= 1;
				curr++;
			}
			ans.PB(6);
			if(!(tmp&1)){
				ans[n] = 10;
				ans[n-1] = 5*primes[curr-1]; 
			}
			for(auto it: ans)
				cout << it << " ";
			cout << endl;
		}
		else{
			ll tmp = n>>1;
			ll curr=2;
			vector<ll> ans;
			ll f=0;
			while(ans.size()<n){
				if(!f){
					ans.PB(2*primes[curr]);
					ans.PB(3*primes[curr]);
				}
				else{
					ans.PB(3*primes[curr]);
					ans.PB(2*primes[curr]);
				}
				curr++;
				f ^= 1;
			}
			if(tmp&1){
				ans[1] = 6;
				ans[n-1] = primes[curr-1]*primes[2];
			}
			for(auto it: ans)
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}