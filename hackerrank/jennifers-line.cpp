//Shounak Dey
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

#define MOD 20000003

int ans=0,l;
int n0=0,n1=0;

void solve(int state,int depth,int a,int b)
{
	if(depth == l)
	{
		ans = (ans+1)%MOD;
		return;
	}
	n0 -= !state;
	n1 -= state;
	if(n0 == 0)
	{
		n0 = a;
		solve(1,depth+1,a,b);
	}
	else if(n1 == 0)
	{
		n1 = b;
		solve(0,depth+1,a,b);
	}
	else
	{
		solve(0,depth+1,a,b);
		solve(1,depth+1,a,b);
	}
	return;
}

int fact(int x)
{
	return x==0?1:x*fact(x-1);
}

int main()
{
	int x,y,a,b;
	read(x);read(y);read(a);read(b);
	a = min(x,a);
	b = min(y,b);
	l = x+y;
	n0 = a;
	n1 = b;
	solve(0,1,a,b);
	solve(1,1,a,b);
	cout << ans/(fact(x)*fact(y)) << endl;
	return 0;
}

