/*=======================
Author    : Shounak Dey
Filename  : a.cpp
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
	REP(test,T){
		cout << "Case #" << test+1 << ": ";
		ll n,p;
		cin >> n >> p;
		vector<string> arr(p);
		REP(i,p)
			cin >> arr[i];
		sort(arr.begin(),arr.end(),[](const auto &lhs, const auto &rhs){
			if(lhs.length() == rhs.length())
				return lhs < rhs;
			return lhs.length() < rhs.length();
		});
		vector<string> pre;
		vector<ll> v(p,1);
		REP(i,p){
			if(!v[i])
				continue;
			pre.PB(arr[i]);
			FOR(j,i+1,p){
				auto res = mismatch(arr[i].begin(),arr[i].end(),arr[j].begin());
				if(res.first == arr[i].end())
					v[j]=0;
			}
		}
		ll ans = 1ll << n;
		for(auto it: pre)
			ans -= 1 << (n-it.length());
		cout << ans << endl;
	}
	return 0;
}