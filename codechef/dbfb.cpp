/*=======================
Author    : Shounak Dey
Filename  : dbfb.cpp
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

#define MOD 1000000007

void mul(vector<vector<ll>> &f,vector<vector<ll>> m){
	vector<vector<ll>> c(2,vector<ll>(2,0));
	REP(i,2){
		REP(j,2){
			REP(k,2)
				c[i][j] = ((f[i][k]*m[k][j])%MOD + c[i][j])%MOD; 
		}
	}
	REP(i,2){
		REP(j,2)
			f[i][j] = c[i][j];
	}
}

void pow(vector<vector<ll>> &f,ll n){
	if(n<=1)
		return;
	pow(f,n/2);
	mul(f,f);
	if(n&1){
		vector<vector<ll>> m(2,vector<ll>(2,1));
		m[1][1] = 0;
		mul(f,m);
	}
	return;
}

int main()
{
	TEST{
		ll n,m;
		cin >> n >> m;
		vector<ll> a(n),b(n);
		REP(i,n)
			cin >> a[i];
		REP(i,n)
			cin >> b[i];
		if(m==1){
			ll ans=0;
			REP(i,n)
				ans = (ans + a[i])%MOD;
			cout << (ans*n)%MOD << endl;
			continue;
		}
		else if(m==2){
			ll ans=0;
			REP(i,n)
				ans = (ans + b[i])%MOD;
			cout << (ans*n)%MOD << endl;
			continue;
		}
		SORTV(a);
		SORTV(b);
		ll diffa=0,diffb=0;
		REP(i,n)
			diffa = (a[i]-a[0] + diffa)%MOD;
		REP(i,n)
			diffb = (b[i]-b[0] + diffb)%MOD;
		m -= 2;
		ll f1,f2;
		vector<vector<ll>> fib(2,vector<ll> (2,1));
		fib[1][1] = 0;
		pow(fib,m);
		// cout << m << endl;
		// REP(i,2){
		// 	REP(j,2)
		// 		cout << fib[i][j] << " ";
		// 	cout << endl;
		// }
		f1 = fib[0][1];
		f2 = fib[0][0];
		// cout << f1 << " " << f2 << endl;
		ll val = ((f1 * a[0])%MOD + (f2 * b[0])%MOD)%MOD;
		ll valb = ((n*val)%MOD + (diffb * f2)%MOD )%MOD;
		// cout << valb << endl;
		ll vala = (((n*n)%MOD *val)%MOD + ((n*diffa)%MOD *f1)%MOD + (n*((diffb*f2)%MOD))%MOD)%MOD;
		cout << (vala)%MOD << endl;
	}
	return 0;
}
