/*=======================
Author    : Shounak Dey
=======================	*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

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

#define MOD 998244553

ll modexp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans = (ans * a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}

ll modinv(ll a){
	return modexp(a,MOD-2);
}

void getCf(vector<vector<ll>> mat,vector<vector<ll>> &cf,ll r, ll c, ll n){
	ll rc=0,cc=0;
	REP(row,n){
		REP(col,n){
			if((row!=r) && (col!=c)){
				// error(rc,cc,n,row,col,mat.size(),cf.size());
				cf[rc][cc++] = mat[row][col];
				if(cc==(n-1)){
					cc=0;
					rc++;
				}
			}
		}
	}
}

ll det(vector<vector<ll>> mat, ll n){
	ll ret=0;
	if(n==1)
		return mat[0][0];
	vector<vector<ll>> cf(n-1,vector<ll>(n-1));
	ll s=1;
	REP(i,n){
		getCf(mat,cf,0,i,n);
		ll tmp = (mat[0][i] * det(cf,n-1));
		if(s==-1)
			tmp = (tmp * (MOD-1))%MOD;
		ret = (ret + tmp)%MOD;;
		s *= -1;
	}
	return ret;
}

int main()
{
	fast_io;
	TEST{
		ll n,m,k;
		cin >> n >> m >> k;
		assert(k<=10);
		vector<vector<ll>> adjs(n,vector<ll>());
		REP(i,m){
			ll x,y;
			cin >> x >> y;
			x--;y--;
			adjs[x].PB(y);
			adjs[y].PB(x);
		}
		vector<vector<ll>> adjb(n*k,vector<ll>(n*k,0));
		REP(i,n){
			for(auto it: adjs[i]){
				REP(j,k){
					adjb[it + j*n][i + j*n]=1;
					adjb[i + j*n][it + j*n]=1;
				}
			}
		}
		n *= k;
		vector<vector<ll>> adjh(n,vector<ll>(n,0));
		REP(i,n){
			REP(j,n)
				adjh[i][j] = !adjb[i][j];
		}
		vector<vector<ll>> d(n,vector<ll>(n,0));
		REP(i,n)
			d[i][i]=0;
		REP(i,n){
			REP(j,n)
				d[i][i] += adjh[i][j];
		}
		n--;
		vector<vector<ll>> mat(n,vector<ll>(n,0));
		REP(i,n){
			REP(j,n)
				mat[i][j] = d[i][j] - adjh[i][j];
		}
		cout << det(mat,n) << endl;
	}
	return 0;
}

