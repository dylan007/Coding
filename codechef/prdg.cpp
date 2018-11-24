/*=======================
Author    : Shounak Dey
Filename  : prdg.cpp
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

typedef struct frac{
	ll n,d;
}frac;

frac midp(frac a,frac b){
	frac res;
	res.n = a.n * b.d + a.d * b.n;
	res.d = a.d * b.d;
	ll g = gcd(res.n,res.d);
	res.n /= g;
	res.d /= g;
	// error(res.n,res.d);
	if(res.n&1)
		res.d <<= 1;
	else
		res.n >>= 1;
	return res;
}

int main()
{
	fast_io;
	TEST{
		ll n;
		cin >> n;
		if(n==1)
			cout << 1 << " " << 2 << " ";
		else if(n==2)
			cout << 1 << " " << 4 << " ";
		else{
			frac l,r;
			l.n = 1;l.d = 4;
			r.n = 1;r.d = 2;
			n-=2;
			REP(i,n-1){
				frac mid = midp(l,r);
				if(i&1)
					l = mid;
				else
					r = mid;
			}
			frac mid = midp(l,r);
			cout << mid.n << " " << mid.d << " ";		
		}
	}
	cout << endl;
	return 0;
}