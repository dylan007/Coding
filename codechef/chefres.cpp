/*=======================
Author    : Shounak Dey
Filename  : chefres.cpp
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
		ll n,m;
		cin >> n >> m;
		vector<pair<ll,ll>> time;
		REP(i,n){
			ll x,y;
			cin >> x >> y;
			time.PB(MK(x,y-1));
		}
		sort(time.begin(),time.end());
		vector<ll> start;
		for(auto it:time)
			start.PB(it.first);
		REP(i,m){
			ll x;
			cin >> x;
			if(x>=time[n-1].second)
				cout << -1 << endl;
			else{
				vector<ll>::iterator it = upper_bound(start.begin(),start.end(),x);
				if(it == start.end())
					cout << 0 << endl;
				else{
					ll pos = it - start.begin();
					if(pos == 0)
						cout << time[0].first-x << endl;
					else if(time[pos].first == x)
						cout << 0 << endl;
					else{
						if(time[pos-1].second>=x)
							cout << 0 << endl;
						else
							cout << time[pos].first - x << endl;
					}
				}
			}
		}
	}	
	return 0;
}