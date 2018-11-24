/*=======================
Author    : Shounak Dey
Filename  : event.cpp
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

int c(string a){
	if(a=="monday")
		return 0;
	if(a=="tuesday")
		return 1;
	if(a=="wednesday")
		return 2;
	if(a=="thursday")
		return 3;
	if(a=="friday")
		return 4;
	if(a=="saturday")
		return 5;
	if(a=="sunday")
		return 6;
}

int main()
{
	fast_io;
	TEST{
		string a,b;
		cin >> a >> b;
		int x,y;
		x = c(a);
		y = c(b);
		if(x<=y)
			x = y-x +1;
		else
			x = 7 - (x-y-1);
		// cout << x << endl;
		int l,r;
		cin >> l >> r;
		int c=0;
		int p = x;
		FOR(i,l,r+1){
			if(i>=x){
				if(((i-x)%7) == 0){
					c++;
					p = i;
				}
			}
		}
		// cout << c << " " << x << endl;
		if(c==0)
			cout << "impossible" << endl;
		else if(c>1)
			cout << "many" << endl;
		else
			cout << p << endl;
	}
	return 0;
}