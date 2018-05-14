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
#define MOD 1000000007

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


struct rat{
	ll num;
	ll den;
};

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

rat ratmul(rat a,rat b)
{
	rat c;
	c.num = (1ll * a.num * b.num)%MOD;
	c.den = (1ll * a.den * b.den)%MOD;
	if(c.num!=0 && c.den!=0){
		ll x = gcd(c.num>0?c.num:(0-c.num),c.den>0?c.den:(0-c.den));
		c.num /= x;
		c.den /= x;
	}
	return c;
}

rat ratadd(rat a,rat b){
	rat c;
	c.num = ((1ll* a.num * b.den) + (1ll * a.den * b.num) + MOD)%MOD;
	c.den = (1ll * b.den * a.den)%MOD;
	if(c.num!=0 && c.den!=0){
		ll x = gcd(c.num>0?c.num:(0-c.num),c.den>0?c.den:(0-c.den));
		c.num /= x;
		c.den /= x;
	}
	return c;
}


void printmat(vector<vector<rat>> mat){
	REP(i,2)
	{
		REP(j,2)
			cout << mat[i][j].num << "/" << mat[i][j].den << " ";
		cout << endl;
	}
}

void power(vector<vector<rat>> &a){
	vector<vector<rat>> ans(2,vector<rat>(2));
	REP(i,2){
		REP(j,2)
		{
			rat c;
			c.num = 0;
			c.den = 1;
			ans[i][j] = c;
			REP(k,2)
				ans[i][j] = ratadd(ans[i][j],ratmul(a[i][k],a[k][j]));
		}
	}
	REP(i,2)
	{
		REP(j,2)
			a[i][j] = ans[i][j];	
	}
}

void multiply(vector<vector<rat>> &a,vector<vector<rat>> &b){
	vector<vector<rat>> ans(2,vector<rat>(2));
	REP(i,2){
		REP(j,2)
		{
			rat c;
			c.num = 0;
			c.den = 1;
			ans[i][j] = c;
			REP(k,2)
				ans[i][j] = ratadd(ans[i][j],ratmul(a[i][k],b[k][j]));
		}
	}
	REP(i,2)
	{
		REP(j,2)
			a[i][j] = ans[i][j];	
	}	
}

void modexp(vector<vector<rat>> &mat,int t){
	vector<vector<rat>> ans(2,vector<rat>(2));
	ans[0][0].num = ans[0][0].den = ans[1][1].num = ans[1][1].den = 1;
	ans[1][0].num = ans[0][1].num = 0;
	ans[1][0].den = ans[0][1].den = 1;
	while(t){
		//printmat(ans);
		if(t&1)
			multiply(ans,mat);
		power(mat);
		t >>= 1;
	}
	REP(i,2){
		REP(j,2)
			mat[i][j] = ans[i][j];
	}
}

ll inv(ll a){
	ll p = MOD-2;
	ll ans=1;
	while(p){
		if(p&1)
			ans = (ans*a)%MOD;
		ans = (ans*ans)%MOD;
		p >>= 1;
	}
	return ans;
}

int main()
{
	TEST{
		double l,d;
		ll t;
		cin >> l >> d >> t;
		vector<vector<rat>> mat(2,vector<rat>(2));
		mat[0][1].num = -1;
		mat[0][1].den = 1;
		mat[1][0].num = 1;
		mat[1][0].den = 1;
		mat[1][1].num = 0;
		mat[1][1].den = 1;
		mat[0][0].num = 2*d;
		mat[0][0].den = l;
		t--;
		// cout << "Initial Matrix" << endl;
		// printmat(mat);
		modexp(mat,t);
		// cout << "Final Matrix" << endl;
		// printmat(mat);
		rat ans;
		rat fin;
		fin.num = d;
		fin.den = l;
		ans.num = 0;
		ans.den = 1;
		ans = ratadd(ans,ratmul(mat[0][0],fin));
		ans = ratadd(ans,mat[0][1]);
		cout << ans.num << "/" << ans.den << endl;
		ans.num = (ans.num * (ll)l)%MOD;
		if(ans.num!=0 && ans.den!=0){
			ll x = gcd(ans.num>0?ans.num:(0-ans.num),ans.den>0?ans.den:(0-ans.den));
			ans.num /= x;
			ans.den /= x;
		}
		cout << ans.num << "/" << ans.den << endl;
		ll x;
		if(ans.num < 0){
			x = inv(ans.den);
			x = (MOD-x)%MOD;
			ans.num = 0-ans.num;
		}
		else{
			x = inv(ans.den);
		}
		//cout << x << endl;
		//cout << ans.num << "/" << ans.den << endl;
		cout << (ans.num*x)%MOD << endl;
 	}
	return 0;
}
