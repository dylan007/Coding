/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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
	TEST{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		vector<ll> x(n,0);
		x[0] = arr[0];
		FOR(i,1,n)
			x[i] = x[i-1]^arr[i];
		ll ans=0;
		map<ll,vector<ll>> ind;
		REP(i,n){
			if(ind.find(x[i])!=ind.end())
				ind[x[i]].PB(i);
			else{
				ind[x[i]] = vector<ll>();
				ind[x[i]].PB(i);
			}
		}
		map<ll,vector<ll>>::iterator mit = ind.begin();
		while(mit != ind.end()){
			if((mit->second.size())<=1){
				mit++;
				continue;
			}
			auto start = mit->second.rbegin();
			auto end = mit->second.rend();
			ll curr= *(start) - 1;
			start++;
			ll c=1;
			while(start != end){
				ans += curr - (*(start)) * c;
				c++;
				curr += *(start) - 1;
				start++;
			}
			mit++;
		}
		FOR(i,1,n){
			if(x[i]==0)
				ans += (i);
		}
		cout << ans << endl;
	}
	return 0;
}

