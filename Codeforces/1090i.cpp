/*=======================
Author    : Shounak Dey
Filename  : 1090i.cpp
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

typedef int64_t i64;

int main()
{
	fast_io;
	TEST{
		i64 n,l,r,x,y,z,b1,b2;
		cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
		auto cmp = [](i64 a,i64 b){
			return a<b;
		};
		set<i64,decltype(cmp)> ms(cmp);
		i64 f=0,ans=LLONG_MAX;
		i64 a1,a2;
		auto func = [](i64 b, i64 l, i64 r){
			return (b % (r-l+1)) + l;
		};
		a1 = func(b1,l,r);
		a2 = func(b2,l,r);
		ms.insert(a1);
		ms.insert(a2);
		if(a2>a1){
			f=1;
			ans = a2*a1;
		}
		FOR(i,2,n){
			i64 b,a;
			i64 tmp = 1;
			tmp <<= 32;
			b = (b1*x + b2*y + z)%(tmp);
			b1 = b2;
			b2 = b;
			a = func(b,l,r);
			i64 m;
			if(a>0)
				m = *(ms.begin());
			else{
				auto ret = lower_bound(ms.begin(),ms.end(),a);
				if(ret==ms.end() || (ret==ms.begin() && (*ret)==a))
					m = a;
				if((*ret)==a)
					ret--;
				m = *ret;
			}
			// cout << a << " " << m << endl;
			if(a > m){
				f = 1;
				ans = ans>(a*m)?a*m:ans;
			}
			ms.insert(a);
		}
		if(f)
			cout << ans << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}