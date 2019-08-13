/*=======================
Author    : Shounak Dey
Filename  : encoding.cpp
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

#define LIM 100010
#define MOD 1000000007

vector<vector<ll>> dp;
vector<ll> factor;

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

ll modinv(ll a){
    return modexp(a,MOD-2);
}

ll calc(string x){
	ll l=x.length();
	ll ret = 0;
	ll pos=l-1;
	ll curr=x[pos]-'0';
	ll p=1;
	pos--;
	while(pos>=0){
		if((x[pos]-'0')!=curr){
			ret = (ret + (curr * p)%MOD)%MOD;
			curr = x[pos]-'0';
		}
		p = (p*10)%MOD;
		pos--;
	}
	ret = (ret + (curr *p)%MOD) %MOD;
	return ret;
}

ll solve(ll l, string num){
	ll ans=0;
	REP(i,(num[0]-'0'))
		ans = (ans + dp[l][i])%MOD;
	ll fsum = 0;
	fsum = ((num[0]-'0')*factor[l-1])%MOD;
	// error(ans);
	FOR(i,1,l){
		ll dprev = num[i-1]-'0';
		ll d = num[i]-'0';
		ll count = (d*factor[l-i-1])%MOD;
		// error(fsum,count);
		ans = (ans + count * fsum)%MOD;
		if(d!=dprev)
			fsum = (fsum + (d * factor[l-i-1])%MOD)%MOD;
		FOR(j,0,d){
			ans = (ans + dp[l-i][j])%MOD;
			// error(dp[l-i][j],l-i,j);
			if(j==dprev){
				ll tmp = (factor[l-i-1]*factor[l-i-1])%MOD;
				tmp = (tmp * j)%MOD;
				ans = (ans + MOD - tmp)%MOD;
			}
			// error(ans);
		}
		// error(ans);
	}
	ans = (ans + calc(num))%MOD;
	return ans;
}

int main()
{
	fast_io;
	dp = vector<vector<ll>>(LIM,vector<ll>(10,0));
	factor = vector<ll>(LIM);
	factor[0] = 1;
	FOR(i,1,LIM)
		factor[i] = (factor[i-1] * 10)%MOD;
	REP(i,10)
		dp[0][i] = 0;
	REP(i,10)
		dp[1][i] = i;
	FOR(i,2,LIM){
		REP(j,10)
			dp[i][0] = (dp[i][0] + dp[i-1][j])%MOD;
		FOR(j,1,10){
			ll tmp;
			REP(k,10){
				// error(i,j,k);
				if(j==k){
					dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
					tmp = (j * factor[i-2])%MOD;
					tmp = (tmp * factor[i-2])%MOD;
					dp[i][j] = (MOD + dp[i][j] - tmp)%MOD;
					tmp = (j * factor[i-1])%MOD;
					tmp = (tmp * factor[i-2])%MOD;
					dp[i][j] = (dp[i][j] + tmp)%MOD;
				}
				else{
					dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
					tmp = (j * factor[i-1])%MOD;
					tmp = (tmp * factor[i-2])%MOD;
					dp[i][j] = (dp[i][j] + tmp)%MOD;
				}
			}
		}
	}
	TEST{
		ll nl,nr;
		string l,r;
		cin >> nl >> l >> nr >> r;
		ll ans = solve(nr,r);
		// cout << ans << endl;
		ans = (ans + MOD - solve(nl,l))%MOD;
		ans = (ans + calc(l))%MOD;
		cout << ans << endl;
	}
	return 0;
}