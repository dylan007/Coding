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

string a,b;

ll eq(ll al,ll ar,ll bl,ll br){
	ll l1 = ar-al+1;
	ll l2 = br-bl+1;
	if(l1!=l2)
		return 0;
	if(l1&1){
		while(al<=ar){
			if(a[al]!=b[bl])
				return 0;
			al++;
			bl++;
		}
		return 1;
	}
	ll as,bs;
	as = al;
	bs = bl;
	ll f=1;
	while(as<=ar){
		if(a[as]!=b[bs]){
			f=0;
			break;
		}
		as++;
		bs++;
	}
	if(f)
		return 1;
	ll am = al + l1/2;
	ll bm = bl + l2/2;
	return (eq(al,am-1,bm,br)&&eq(am,ar,bl,bm-1)) || ((eq(al,am-1,bl,bm-1) && eq(am,ar,bm,br)));
}

int main()
{
	fast_io;
	cin >> a >> b;
	ll f = eq(0,a.length()-1,0,b.length()-1);
	if(f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

