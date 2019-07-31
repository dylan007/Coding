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
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	REP(i,n) cin >> a[i];
	REP(i,n) cin >> b[i];
	SORTV(b);
	map<int,int> x;
	REP(i,n)
		x[b[i]]++;
	REP(i,n){
		auto it = x.lower_bound(n-a[i]);
		int pos;
		if(it==x.end()){
			it--;
			auto it2 = x.begin();
			int l,r;
			l = (a[i]+it->F)%n;
			r = (a[i]+it2->F)%n;
			if(l>r)
				it = x.begin();
			pos = it->F;
		}
		else
			pos = it->F;
		(it->S)--;
		if(it->S == 0)
			x.erase(it);
		cout << (a[i]+pos)%n << " ";
	}
	cout << endl;
	return 0;
}

