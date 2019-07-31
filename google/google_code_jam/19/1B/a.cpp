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

#define MOD (ll)(1ll<<63)


ll mul(ll a,ll b) {return (a*b)%MOD;}
ll add(ll a,ll b) {return (a+b)%MOD;}
ll sub(ll a,ll b){
	if(a>b)
		return (a-b)%MOD;
	return (a-b+MOD)%MOD;
}

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

int main()
{
	fast_io;
	int T,w;
	cin >> T >> w;
	cout << mul(10,modinv(5));
	assert(w==6);
	REP(test,T){
		ll arr[6];
		ll diff[6];
		REP(i,6){
			cout << i+1 << endl << flush;
			cin >> arr[i];
			if(i>0)
				diff[i] = sub(arr[i],arr[i-1]);
		}

		ll out[6];
		out[0] = mul(sub(add(arr[5],arr[0]),add(arr[2],mul(2,arr[1]))),modinv(24));
		out[0] = mul(sub(arr[5],mul(2,arr[2])),modinv(48));
		out[1] = sub(diff[1],arr[0]);
		out[2] = sub(diff[2],mul(2,arr[0]));
		out[3] = sub(diff[3],add(mul(4,arr[0]),arr[1]));
		out[4] = sub(diff[4],mul(8,arr[0]));
		out[5] = sub(diff[5],add(mul(16,arr[0]),add(mul(2,arr[1]),arr[2])));
		REP(i,6)
			cout << out[i] << " ";
		cout << endl << flush;
		int ret;
		cin >> ret;
		if(ret==-1)
			exit(0);
	}
	return 0;
}

