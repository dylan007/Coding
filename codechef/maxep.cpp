/*=======================
Author    : Shounak Dey
Filename  : maxep.cpp
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

#define flush fflush(stdout);

int main()
{
	fast_io;
	ll n,c;
	ll tot = 1000;
	cin >> n >> c;
	if(n==1){
		cout << 3 << " " << 1 << endl;
		flush;
	}
	else if(n<=10){
		ll bsize = 1;
		ll l,r;
		l = 1;
		r = min(n,l + bsize - 1);
		while(1){
			cout << 1 << " " << r << endl;
			flush;
			ll res;
			cin >> res;
			if(res == 1)
				break;
			l = r+1;
			r = min(n,l+bsize - 1);
		}
		cout << 2 << endl;
		flush;
		cout << 3 << " " << r << endl;
		flush;
	}
	else if(n<=1000){
		ll bsize = 100;
		ll l,r;
		l = 1;
		r = min(n,l + bsize - 1);
		while(1){
			cout << 1 << " " << r << endl;
			flush;
			ll res;
			cin >> res;
			if(res == 1)
				break;
			l = r+1;
			r = min(n,l+bsize - 1);
		}
		cout << 2 << endl;
		flush;
		bsize = 1;
		r = min(n,l + bsize-1);
		while(1){
			cout << 1 << " " << r << endl;
			flush;
			ll res;
			cin >> res;
			if(res == 1)
				break;
			l = r+1;
			r = min(n,l+bsize - 1);
		}
		cout << 2 << endl;
		flush;
		cout << 3 << " " << r << endl;
		flush;
	}
	else{
		ll bsize = 1000;
		ll l,r;
		l = 1;
		r = l + bsize - 1;
		while(1){
			cout << 1 << " " << r << endl;
			flush;
			ll res;
			cin >> res;
			if(res == 1)
				break;
			l = r+1;
			r = min(n,l+bsize - 1);
		}
		cout << 2 << endl;
		flush;
		bsize = 100;
		r = min(n,l + bsize-1);
		while(1){
			cout << 1 << " " << r << endl;
			flush;
			ll res;
			cin >> res;
			if(res == 1)
				break;
			l = r+1;
			r = min(n,l+bsize - 1);
		}
		cout << 2 << endl;
		bsize = 1;
		r = min(n,l + bsize-1);
		while(1){
			cout << 1 << " " << r << endl;
			flush;
			ll res;
			cin >> res;
			if(res == 1)
				break;
			l = r+1;
			r = min(n,l+bsize - 1);
		}
		cout << 2 << endl;
		flush;
		cout << 3 << " " << r << endl;
		flush;
	}
	return 0;
}