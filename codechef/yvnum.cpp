/*=======================
Author    : Shounak Dey
Filename  : yvnum.cpp
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
#define MOD 1000000007

ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		a = (a * a)%MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	fast_io;
	ll mi = modexp(10,MOD-2);
	TEST{
		string n;
		cin >> n;
		ll ans=0;
		ll p = modexp(10,n.length()-1);
		rotate(n.begin(),n.begin()+n.length()-1,n.end());
		ll curr = 0;
		REP(i,n.length()-1)
			curr = ((curr * 10)%MOD + (n[i]-'0'))%MOD;
		ans = ((curr * 10)%MOD + (n[n.length()-1]-'0'))%MOD;
		curr = ans;
		ll pos = n.length()-1;
		ll fact = (p*10)%MOD;
		while(pos){
			ll tmp = (curr - (n[pos]-'0')+MOD)%MOD;
			tmp = (tmp * mi)%MOD;
			curr = (((n[pos]-'0')*p)%MOD + tmp)%MOD;
			ans = (ans + (curr*fact)%MOD)%MOD;
			fact = ((fact * p)%MOD * 10)%MOD;
			pos--;
		}
		cout << ans << endl;
	}
	return 0;
}