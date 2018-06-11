/*=======================
Author    : Shounak Dey
Filename  : euler002.cpp
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

#define lim 4*1e+16

int main()
{
	cout << fixed;
	vector<ull> fib;
	ull x=1,y=2;
	while(y<=lim){
		if((y&1) == 0)
			fib.PB(y);
		ull t;
		t = x+y;
		x = y;
		y = t;
	}
	// for(auto it:fib)
	// 	cout << it << " ";
	// cout << endl; 
	int n = fib.size();
	vector<ull> pre(n);
	pre[0] = fib[0];
	FOR(i,1,n)
		pre[i] = pre[i-1] + fib[i];
	TEST{
		ull x;
		cin >> x;
		if(x<fib[0])
			cout << 0 << endl;
		else if(x>fib[n-1])
			cout << pre[n-1] << endl;
		else{
			int pos = lower_bound(fib.begin(),fib.end(),x) - fib.begin();
			pos -= (fib[pos] != x);
			cout << pos << endl;
			cout << pre[pos] << endl;
		}
	}
	return 0;
}