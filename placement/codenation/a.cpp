/*=======================
Author    : Shounak Dey
Filename  : a.cpp
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

#define LIM 2000010

int main()
{
	fast_io;
	ll l1,r1;
	ll l2,r2;
	cin >> l1 >> r1;
	cin >> l2 >> r2;
	vector<ll> spf(LIM,-1);
	ll slim = (ll)sqrt(LIM);
	FOR(i,2,LIM){
		if(spf[i]==-1){
			ll curr=2*i;
			while(curr < LIM){
				if(spf[curr==-1])
					spf[curr] = i;
				curr+=i;
			}
		}
	}
	vector<ll> s(LIM,0);
	auto modexp = [](ll a,ll b){
		ll ans=1;
		while(b){
			if(b&1)
				ans *= a;
			a *= a;
			b >>= 1;
		}
		return ans;
	};
	REP(i,LIM){
		ll curr=i;
		map<ll,ll> c;
		while(spf[curr]!=-1){
			c[spf[curr]]++;
			curr /= spf[curr];
		}
		c[spf[curr]]++;
		s[i]=1;
		for(auto it: c)
			s[i] *= (modexp(it.F,it.S)-1)/(it.F-1);
	}
	double p1=0,p2=0;
	FOR(i,l1,r1+1)
		p1 += s[i];
	FOR(i,l2,r2+1)
		p2 += s[i];
	REP(i,20)
		cout << s[i] << " ";
	cout << endl;
	p1 /= (r1-l1+1);
	p2 /= (r2-l2+1);
	if(p1>p2)
		cout << "A" << endl;
	else if(p1 < p2)
		cout << "B" << endl;
	else
		cout << "Draw" << endl;
	return 0;
}