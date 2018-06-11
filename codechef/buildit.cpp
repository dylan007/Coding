/*=======================
Author    : Shounak Dey
Filename  : buildit.cpp
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

#define MOD 163577857

ll modexp(ll x,ll p){
	ll ans=1;
	while(p){
		if(p%2)
			ans = (ans * x)%MOD;
		x = (x*x)%MOD;
		p /= 2;
	}
	return ans;
}

ll inv(ll x){
	return modexp(x,MOD-2);
}

int main()
{
	ll n,h,x,k;
	cin >> n >> h >> x >> k;
	vector<ll> p(n);
	REP(i,n){
		cin >> p[i];
		p[i]--;
	}
	// cout << "W" << endl;
	vector<ll> a(k),c(k);
	REP(i,k)
		cin >> a[i];
	REP(i,k)
		cin >> c[i];
	vector<ll> pre(h,0);
	REP(i,n)
		pre[p[i]]++;
	FOR(i,1,h)
		pre[i] += pre[i-1];
	// for(auto it:pre)
	// 	cout << it << " ";
	// cout << endl;
	vector<ll> probs(h);
	ll tot = 0;
	REP(i,k){
		probs[i] = a[i];
		tot = (tot + probs[i]) %MOD;
	}
	FOR(i,k,h){
		ll ans=0;
		int j = i-k;
		int r = k-1;
		while(j<i){
			ans = (ans + (probs[j]*c[r])%MOD)%MOD;
			j++;
			r--;
		}
		probs[i] = ans;
		tot = (tot + probs[i])%MOD;
	}
	// REP(i,h)
	// 	cout << probs[i] << " ";
	// cout << endl;
	ll ans=0;
	REP(i,h){
		ll count;
		ll l = i;
		ll r = (i+x-1)%h;
		// error(i,x,l,r);
		if(l>r){
			ll left,right;
			left = pre[r];
			if(l==0)
				right = pre[h-1];
			else
				right = pre[h-1]-pre[l-1];
			count = left + right;
		}
		else{
			ll left,right;
			if(l==0)
				left = 0;
			else
				left = pre[l-1];
			right = pre[h-1]-pre[r];	
			count = pre[h-1]-left-right;	
		}

		// error(count);
		// cout << endl;
		ans = (ans + (count * probs[i])%MOD)%MOD;
	}
	// cout << ans << " " << tot << endl; 
	cout << (ans * inv(tot))%MOD << endl;
	return 0;
}