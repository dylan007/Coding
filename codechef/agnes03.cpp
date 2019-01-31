/*=======================
Author    : Shounak Dey
Filename  : agnes03.cpp
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
	TEST{
		double a1,a2,a3;
		double b1,b2,b3;
		cin >> a1 >> a2 >> a3;
		cin >> b1 >> b2 >> b3;
		double m1=0,m2=0;
		ll f1=0,f2=0;
		if(a2==0)
			f1 = 1;
		else
			m1 = (a1/a2);
		if(b2==0)
			f2 = 1;
		else 
			m2 = (b1/b2);
		// error(m1,m2);
		if(f1 && f2){
			a3 = a3/a1;
			b3 = b3/b1;
			if(a3==b3)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else if((f1^f2))
			cout << 1 << endl;
		else if(m1==m2){
			a3 /= a2;
			b3 /= b2;
			if(a3==b3)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else
			cout << 1 << endl;
	}
	return 0;
}