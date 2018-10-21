/*=======================
Author    : Shounak Dey
Filename  : broclk.cpp
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

ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}

ll inv(ll a){
	return modexp(a,MOD-2);
}

vector<vector<ll>> mult(vector<vector<ll>> a,vector<vector<ll>> b){
	vector<vector<ll>> ans(2,vector<ll>(2,0));
	REP(i,2){
		REP(j,2){
			REP(k,2)
				ans[i][j] = (ans[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
		}
	}
	return ans;
}

int main()
{
	TEST{
		ll d,l,t;
		cin >> l >> d >> t;
		ll cos = (d*inv(l))%MOD;
		vector<vector<ll>> mat(2,vector<ll>(2,0));
		mat[0][0] = (2*cos)%MOD;
		mat[0][1] = MOD-1;
		mat[1][0] = 1;
		t--;
		vector<vector<ll>> ans(2,vector<ll>(2,0));
		ans[0][0] = ans[1][1] = 1;
		while(t){
			if(t&1)
				ans = mult(ans,mat);
			t >>= 1;
			mat = mult(mat,mat);
		}
		// for(auto it: ans){
		// 	for(auto j:it)
		// 		cout << j << " ";
		// 	cout << endl;
		// }
		ll out = ((ans[0][0]*cos)%MOD + (ans[0][1]))%MOD;
		cout << (out*l)%MOD << endl;
	}
	return 0;
}