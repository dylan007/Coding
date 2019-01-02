/*=======================
Author    : Shounak Dey
Filename  : beaukono.cpp
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
	//Use parity for each node to identify remote nodes which are at odd distance from each other.
	TEST{
		ll n;
		cin >> n;
		unordered_set<ll> zero,one;
		vector<ll> color(n+2,0);
		ll num=0,ans=0;
		zero.insert(1);
		color[1] = 0;
		FOR(i,1,n+1){
			ll x;
			cin >> x;
			color[i+1] = 1 - color[x];
			if(x==1)
				num++;
			if(color[i+1]){
				if((x==1 && num>1 && (zero.find(x)!=zero.end())) || (x!=1 && zero.find(x)!=zero.end()))
					zero.erase(x);
				one.insert(i+1);
			}
			else{
				if((x==1 && num>1 && (one.find(x)!=one.end())) || (x!=1 && one.find(x) != one.end()))
					one.erase(x);
				zero.insert(i+1);
			}
			ans += max(zero.size(),one.size());
		}
		cout << ans << endl;
	}
	return 0;
}