/*=======================
Author    : Shounak Dey
Filename  : buckets.cpp
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

typedef struct{
	ll n,d;
}frac;

frac mul(frac a,frac b){
	frac tmp;
	tmp.n = a.n*b.n;
	tmp.d = a.d*b.d;
	if(tmp.n==0)
		return tmp;
	ll g = gcd(tmp.n,tmp.d);
	tmp.n /= g;
	tmp.d /= g;
	return tmp;
}

frac sub(frac a,frac b){
	frac tmp;
	tmp.n = b.d*a.n - a.d*b.n;
	tmp.d = a.d * b.d;
	if(tmp.n==0)
		return tmp;
	ll g = gcd(tmp.n,tmp.d);
	tmp.n /= g;
	tmp.d /= g;
	return tmp;
}

frac add(frac a,frac b){
	frac tmp;
	tmp.n = b.d*a.n + a.d*b.n;
	tmp.d = a.d * b.d;
	if(tmp.n==0)
		return tmp;
	ll g = gcd(tmp.n,tmp.d);
	tmp.n /= g;
	tmp.d /= g;
	return tmp;
}

int main()
{
	fast_io;
	ll n,k;
	cin >> n >> k;
	ll count[k][n];
	REP(i,n) REP(j,k) cin >> count[j][i];

	ll tot[n];
	REP(i,n){
		tot[i]=0;
		REP(j,k)
			tot[i] += count[j][i];
	}
	frac prob[k][n];
	REP(i,k)
		prob[i][0] = {count[i][0],tot[0]};
	FOR(i,1,n){
		REP(j,k){
			prob[j][i] = add(mul({count[j][i],tot[i]+1},sub({1,1},prob[j][i-1])),mul({count[j][i]+1,tot[i]+1},prob[j][i-1]));
		}
	}
	// REP(j,n){
	// 	REP(i,k){
	// 		error(j,i);
	// 		cout << prob[i][j].n << " " << prob[i][j].d << endl;
	// 	}
	// }
	cout << setprecision(15) << fixed;
	REP(i,k)
		cout << ((double)(prob[i][n-1].n)) / ((double)prob[i][n-1].d) << " ";
	cout << endl;
	return 0;
}