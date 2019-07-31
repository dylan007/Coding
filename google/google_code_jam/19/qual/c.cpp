/*=======================
Author    : Shounak Dey
Filename  : c.cpp
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

int main()
{
	fast_io;
	int T;
	cin >> T;
	vector<ll> primes;
	auto check = [](ll x){
		ll curr=2;
		if(x < curr)
			return 0;
		while(curr*curr <= x){
			if((curr%x)==0)
				return 0;
			curr++;
		}
		return 1;
	};
	FOR(i,1,10001){
		if(check(i))
			primes.PB(i);
	}
	auto spf = [&](ll x){
		for(auto it:primes){
			if(x<it)
				break;
			if((x%it)==0)
				return it;
		}
		return x;
	};
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll n,l;
		cin >> n >> l;
		vector<ll> arr(l);
		REP(i,l)
			cin >> arr[i];
		// ll x = gcd(arr[0],arr[1]);
		// vector<ll> primes;
		// primes.PB((arr[0]/x));
		// FOR(i,1,l+1)
		// 	primes.PB(arr[i-1]/primes[i-1]);
		// set<ll> sp;
		// for(auto it: primes)
		// 	sp.insert(it);
		// for(auto it:sp)
		// 	cout << it << " ";
		// cout << endl;
		// map<ll,ll> pos;
		// ll curr=0;
		// for(auto it: sp){
		// 	pos[it] = curr;
		// 	curr++;
		// }
		// string out = "";
		// cout << primes.size() << " " << l << endl;
		// for(auto it:primes)
		// 	out += (pos[it] + 'A');
		// cout << out << endl;
		set<ll> sp;
		for(auto it:arr){
			ll x = spf(it);
			sp.insert(x);
			sp.insert(it/x);
		}
		map<ll,ll> pos;
		ll curr=0;
		for(auto it:sp){
			pos[it] = curr;
			curr ++;
		}
		string out = "";

		curr = gcd(arr[0],arr[1]);
		out += (pos[(arr[0]/curr)] + 'A');
		REP(i,l-1){
			curr = gcd(arr[i],arr[i+1]);
			out += (pos[curr] + 'A');
		}
		curr = arr[l-1]/curr;
		out += (pos[curr] + 'A');
		cout << out << endl;
	}
	return 0;
}