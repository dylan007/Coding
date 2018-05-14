/*=======================
Author    : Shounak Dey
Filename  : gcddiv.cpp
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

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

int check(ll ans,ll k,vector<ll> primes){
	int flag=0;
	for(ll i=2;i*i <= ans;i++){
		if((ans%i)==0){
			flag=1;
			break;
		}
	}
	if(!flag){
		return ans>k;
	}
	REP(i,primes.size()){
		if(primes[i] <= k)
			continue;
		if((ans % primes[i]) == 0)
			return 1;
	}
	return 0;
}

void sieve(vector<ll> &primes){
	vector<ll> flag(10000000,0);
	for(ll i=2;i<=10000000;i++){
		if(flag[i] == 0){
			primes.PB(i);
			for(ll j=2*i;j<=10000000;j+=i)
				flag[j] = 1;
		}
	}
}

int main()
{
	vector<ll> primes;
	sieve(primes);
	TEST{
		ll n,k;
		cin >> n >> k;
		ll x = 0;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		ll ans = arr[0];
		FOR(i,1,n)
			ans = gcd(arr[i],ans);
		if(check(ans,k,primes))
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
