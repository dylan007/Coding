/*=======================
Author    : Shounak Dey
Filename  : gmedian.cpp
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

ll inv(ll a){
	return modexp(a,MOD-2);
}

int main()
{
	fast_io;
	TEST{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		SORTV(arr);
		ll ans=0;
		ll lim = n/2 + n%2;
		REP(i,lim){
			// cout << endl;
			ll l = arr[i]-1,r = n-arr[i];
			ll p1=l,p2=r;
			ll curr=1;
			ll temp = 1;
			while(l>=1){
				temp = (temp + (p1 * p2)%MOD)%MOD;
				// error(p1,p2,l,r);
				l--;
				r--;
				curr++;
				p1 = (p1 * l)%MOD;
				p1 = (p1 * inv(curr))%MOD;
				p2 = (p2 * r)%MOD;
				p2 = (p2 * inv(curr))%MOD;
			}
			if((n&1) && (i==(lim-1)))
				ans = (ans + temp)%MOD;
			else
				ans = (ans + (2*temp)%MOD)%MOD;
			// error(ans);
		}
		cout << ans << endl;
	}
	return 0;
}