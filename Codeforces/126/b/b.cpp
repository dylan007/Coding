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

#define MOD 1000000009
#define P 31

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

int main()
{
	fast_io;
	string a;
	cin >> a;
	vector<ll> hval(a.length(),0);
	ll curr=P;
	vector<ll> inv(a.length(),0);
	REP(i,a.length()){
		if(i==0)
			hval[i] = (curr * (a[i]-'a'))%MOD;
		else
			hval[i] = (hval[i-1] + ((curr*(a[i]-'a'))%MOD))%MOD;
		curr = (curr * P)%MOD;
		inv[i] = modinv(modexp(P,i));
	}
	vector<ll> valid;
	REP(i,a.length()){
		ll pref,suff;
		pref = hval[i];
		if(i!=(a.length()-1)){
			suff = (hval[a.length()-1] - hval[a.length()-1-i-1] + MOD)%MOD;
			suff = (suff * inv[a.length()-1-i])%MOD;
		}
		else
			suff = hval[a.length()-1];
		if(suff == pref)
			valid.PB(i);
	}

	auto rkp = [&](ll len){
		ll start,end;
		start = 1;
		end = a.length()-1-len;
		while(start<=end){
			ll hsh = (hval[start+len-1] - hval[start-1] + MOD)%MOD;
			hsh = (hsh * inv[start])%MOD;
			if(hsh == hval[len-1])
				return 1;
			start++;
		}
		return 0;
	};

	auto printPrefix = [&](ll pos){
		ll start=0;
		while(start<=pos)
			cout << a[start++];
		cout << endl;
		return;
	};

	ll low,high,mid;
	low = 0;
	high = valid.size()-1;
	ll f=0;
	while(low<=high){
		mid = (low+high)>>1;
		f = rkp(valid[mid]+1);
		if(mid == low)
			break;
		if(f)
			low = mid;
		else
			high = mid-1;
	}
	if(f)
		printPrefix(valid[mid]);
	else
		cout << "Just a legend" << endl;
	return 0;
}

