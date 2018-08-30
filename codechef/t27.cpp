/*=======================
Author    : Shounak Dey
Filename  : t27.cpp
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

int main()
{
	TEST{
		int n;
		cin >> n;
		vector<ll> arr(n);
		vector<ll> sqr(n);
		REP(i,n){
			cin >> arr[i];
			sqr[i] = arr[i]*arr[i];
		}
		unordered_map<ll,ll> c1,c2;
		REP(i,n){
			REP(j,n){
				ll p1,p2;
				p1 = sqr[i] + arr[j];
				if(c1.find(p1) == c1.end())
					c1[p1] = 1;
				else
					c1[p1]++;
			}
		}
		REP(i,n){
			REP(j,n){
				ll p2;
				p2 = sqr[i] + sqr[j];
				if(c1.find(p2) != c1.end()){
					if(c2.find(p2) == c2.end())
						c2[p2] = 1;
					else
						c2[p2]++;
				}
			}
		}
		ll ans=0;
		unordered_map<ll,ll>::iterator it = c2.begin();
		while(it != c2.end()){
			if(c1.find(it->first) != c1.end())
				ans += (it->second)*c1[it->first];
			it++;
		}
		cout << ans << endl;
	}
	return 0;
}