/*=======================
Author    : Shounak Dey
Filename  : bps.cpp
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

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

int main()
{
	fast_io;
	TEST{
		ll n,m;
		cin >> n >> m;
		vector<ll> arr(n);
		REP(i,n)
			cin >> arr[i];
		ll ans=0;
		ll tot=1;
		FOR(i,1,n+1)
			tot *= i;
		vector<ll> perm;
		vector<pair<ll,ll>> range;
		REP(i,m){
			perm.PB(i);
			ll x,y;
			cin >> x >> y;
			range.PB(MK(x-1,y-1));
		}
		vector<ll> b(arr);
		REP(i,m){
			ll l,r;
			l = range[i].first;
			r = range[i].second;
			while(l<r){
				b[l] += b[r];
				b[r] = b[l]-b[r];
				b[l] -= b[r];
				l++;r--;
			}
		}
		do{
			vector<ll> temp = arr;
			REP(i,m){
				ll l,r;
				l = range[perm[i]].first;
				r = range[perm[i]].second;
				while(l<r){
					temp[l] += temp[r];
					temp[r] = temp[l]-temp[r];
					temp[l] -= temp[r];
					l++;r--;
				}
			}
			for(auto it: temp)
				cout << it << " ";
			cout << endl;
			REP(i,n){
				if(b[i]!=temp[i])
					continue;
			}
			ans++;
		}while(next_permutation(perm.begin(),perm.end()));
		ll g = gcd(ans,tot);
		cout << ans/g << "/" << tot/g << endl;
	}	
	return 0;
}