/*=======================
Author    : Shounak Dey
Filename  : 965c.cpp
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

ull f(ull n,ull k,ull m,ull i){
	ull x1 = i + (i-1)*(k-1);
	ull m1,m2;
	if((n/x1 > m))
		m1 = 0;
	else{
		if(n/x1 == 0)
			m1 = min(m,n%x1);
		else
			m1 = (n/x1)*i;
	}
	ull x2 = i*k;
	if((n/x2 > m))
		m2 = 0;
	else{
		if(n/x2 == 0)
			m2 = min(m,n%x1);
		else
			m2 = (n/x2)*i + (n%x2 >= (n/x2))*(n/x2);
	}
	cout << x1 << " " << x2 << endl;
	cout << m1 << " " << m2 << " " << i << endl;
	error(n/x1,n/x2,m);
	cout << endl;	
	return max(m1,m2);
}

int main()
{
	ull n,k,m,d;
	cin >> n >> k >> m >> d;
	ull M=0;
	for(int i=1;i<=d;i++){
		M = max(M,f(n,k,m,i));
	}
	cout << M << endl;
	return 0;
}
