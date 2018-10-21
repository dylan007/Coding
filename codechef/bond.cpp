/*=======================
Author    : Shounak Dey
Filename  : bond.cpp
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
	vector<int> bnext(7,0),wnext(7,0);
	bnext[0] = 1;
	bnext[1] = 3;
	bnext[3] = 2;
	bnext[2] = 4;
	bnext[4] = 6;
	bnext[6] = 5;
	bnext[5] = 0;
	wnext[0] = 0;
	wnext[1] = 2;
	wnext[2] = 3;
	wnext[3] = 5;
	wnext[5] = 4;
	wnext[4] = 6;
	wnext[6] = 1;
	TEST{
		string a;
		cin >> a;
		int curr = 0;
		REP(i,a.length()){
			int x = a[i]-'0';
			while(x--)
				curr = bnext[curr];
			curr = wnext[curr];
		}
		cout << char(curr+'A') << endl;
	}
	return 0;
}