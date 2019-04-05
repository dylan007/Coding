/*=======================
Author    : Shounak Dey
Filename  : 1133a.cpp
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
	string a;
	cin >> a;
	string b;
	cin >> b;
	int h1 = (a[0]-'0')*10 + (a[1]-'0');
	int h2 = (b[0]-'0')*10 + (b[1]-'0');
	int m1 = (a[3]-'0')*10 + (a[4]-'0');
	int m2 = (b[3]-'0')*10 + (b[4]-'0');
	int m = m2 - m1 + (h2 - h1)*60;
	m >>= 1;
	error(h1,h2,m1,m2,m);
	int ms,hs;
	hs = h1 + (m1 + m)/60;
	ms = (m1 + m)%60;
	string out = "";
	if(hs<=9)
		out += "0"+to_string(hs);
	else
		out += to_string(hs);
	out += ":";
	if(ms<=9)
		out += "0"+to_string(ms);
	else
		out += to_string(ms);
	cout << out << endl;
	return 0;
}